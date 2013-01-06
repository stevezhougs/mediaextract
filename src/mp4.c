#include "mp4.h"

struct ftyp {
	const char *brand;
	const char *ext;
};

static const struct ftyp mp4_ftyps[] = {
	{ "3g2a", "3g2" },
	{ "3g2b", "3g2" },
	{ "3g2c", "3g2" },
	{ "3ge6", "3gp" },
	{ "3ge7", "3gp" },
	{ "3gg6", "3gp" },
	{ "3gp1", "3gp" },
	{ "3gp2", "3gp" },
	{ "3gp3", "3gp" },
	{ "3gp4", "3gp" },
	{ "3gp5", "3gp" },
	{ "3gp6", "3gp" },
	{ "3gp6", "3gp" },
	{ "3gp6", "3gp" },
	{ "3gs7", "3gp" },
	{ "avc1", 0 },
	{ "CAEP", 0 },
	{ "caqv", 0 },
	{ "CDes", 0 },
	{ "da0a", 0 },
	{ "da0b", 0 },
	{ "da1a", 0 },
	{ "da1b", 0 },
	{ "da2a", 0 },
	{ "da2b", 0 },
	{ "da3a", 0 },
	{ "da3b", 0 },
	{ "dmb1", 0 },
	{ "dmpf", 0 },
	{ "drc1", "mp4" },
	{ "dv1a", 0 },
	{ "dv1b", 0 },
	{ "dv2a", 0 },
	{ "dv2b", 0 },
	{ "dv3a", 0 },
	{ "dv3b", 0 },
	{ "dvr1", "dvb" },
	{ "dvt1", "dvb" },
	{ "F4V ", "f4v" },
	{ "F4P ", "f4p" },
	{ "F4A ", "f4a" },
	{ "F4B ", "f4b" },
	{ "isc2", 0 },
	{ "iso2", "mp4" },
	{ "isom", "mp4" },
	{ "JP2 ", "jp2" },
	{ "JP20", "jp2" },
	{ "jpm ", "jpm" },
	{ "jpx ", "jpx" },
	{ "KDDI", "3gp" },
	{ "M4A ", "m4a" },
	{ "M4B ", "m4b" },
	{ "M4P ", "m4p" },
	{ "M4V ", "m4v" },
	{ "M4VH", "m4v" },
	{ "M4VP", "m4v" },
	{ "mj2s", "jp2" },
	{ "mjp2", "jp2" },
	{ "mmp4", "mp4" },
	{ "mp21", 0 },
	{ "mp41", "mp4" },
	{ "mp42", "mp4" },
	{ "mp71", "mp4" },
	{ "MPPI", 0 },
	{ "mqt ", "mqv" },
	{ "MSNV", "mp4" },
	{ "NDAS", 0 },
	{ "NDSC", "mp4" },
	{ "NDSH", "mp4" },
	{ "NDSM", "mp4" },
	{ "NDSP", "mp4" },
	{ "NDSS", "mp4" },
	{ "NDXC", "mp4" },
	{ "NDXH", "mp4" },
	{ "NDXM", "mp4" },
	{ "NDXP", "mp4" },
	{ "NDXS", "mp4" },
	{ "odcf", 0 },
	{ "opf2", 0 },
	{ "opx2", 0 },
	{ "pana", 0 },
	{ "qt  ", "mov" },
	{ "ROSS", 0 },
	{ "sdv ", 0 },
	{ "ssc1", 0 },
	{ "ssc2", 0 },
	{ 0     , 0 }
};

static const char *mp4_bodyatom_types[] = {
	"moov", "mdat", "free", "skip", "wide", "pnot", 0
};

struct mp4_atom_head {
	uint32_t size;
	uint32_t type;
};

struct mp4_type_atom {
	uint32_t size;
	uint32_t type;
	uint32_t major_brand;
	uint32_t minor_version;
	uint32_t compatible_brands[];
};

static const char *mp4_find_ext(uint32_t brand)
{
	for (const struct ftyp *ftyp = mp4_ftyps; ftyp->brand; ++ ftyp)
	{
		if (MAGIC(ftyp->brand) == brand)
		{
			if (!ftyp->ext) return "mp4";
			return ftyp->ext;
		}
	}
	return NULL;
}

static int mp4_isbodyatom_type(uint32_t type)
{
	for (const char **atom = mp4_bodyatom_types; *atom; ++ atom)
	{
		if (MAGIC(atom) == type)
		{
			return 1;
		}
	}
	return 0;
}

int mp4_isfile(const uint8_t *data, size_t input_len, struct file_info *info)
{
	const char *ext = 0;
	const struct mp4_type_atom *type = (struct mp4_type_atom *)data;

	if (input_len < MP4_HEADER_SIZE || type->type != MP4_MAGIC)
		return 0;

	size_t length = be32toh(type->size);

	if (length < MP4_HEADER_SIZE || input_len < length)
		return 0;

	ext = mp4_find_ext(type->major_brand);

	if (!ext)
	{
		for (const uint32_t *brand = type->compatible_brands,
			*end = (const uint32_t*)(data + length);
			brand < end; ++ brand)
		{
			if (*brand)
			{
				ext = mp4_find_ext(*brand);
				if (ext) break;
			}
		}
	}

	if (!ext)
		return 0;

	/* Now I'm fairly sure it is a mp4 file, so if it now ends
	 * prematurely I assume it is a truncated mp4 file. */
	while (length < input_len - 8)
	{
		const struct mp4_atom_head *head = (const struct mp4_atom_head *)(data + length);
		size_t size = be32toh(head->size);
		if (size < 8 || !mp4_isbodyatom_type(head->type) || (size_t)(-1) - size < length)
			break;
		length += size;
		if (length > input_len) length = input_len;
	}

	if (info)
	{
		info->length = length;
		info->ext    = ext;
	}

	return 1;
}
