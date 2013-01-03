#ifndef AUDIOEXTRACT_ASF_H__
#define AUDIOEXTRACT_ASF_H__

#include "audioextract.h"

#define ASF_MAGIC MAGIC("\x30\x26\xB2\x75")
#define ASF_HEADER_SIZE 134
#define ASF_OBJECT_SIZE 24

#define ASF_GUID_SIZE 16
#define ASF_Header_Object_GUID "\x30\x26\xB2\x75\x8E\x66\xCF\x11\xA6\xD9\x00\xAA\x00\x62\xCE\x6C"
#define ASF_Data_Object_GUID "\x36\x26\xB2\x75\x8E\x66\xCF\x11\xA6\xD9\x00\xAA\x00\x62\xCE\x6C"
#define ASF_Simple_Index_Object_GUID "\x90\x08\x00\x33\xB1\xE5\xCF\x11\x89\xF4\x00\xA0\xC9\x03\x49\xCB"
#define ASF_Index_Object_GUID "\xD3\x29\xE2\xD6\xDA\x35\xD1\x11\x90\x34\x00\xA0\xC9\x03\x49\xBE"
#define ASF_Media_Object_Index_Object_GUID "\xF8\x03\xB1\xFE\xAD\x12\x64\x4C\x84\x0F\x2A\x1D\x2F\x7A\xD4\x8C"
#define ASF_Timecode_Index_Object_GUID "\xD0\x3F\xB7\x3C\x4A\x0C\x03\x48\x95\x3D\xED\xF7\xB6\x22\x8F\x0C"
#define ASF_File_Properties_Object_GUID "\xA1\xDC\xAB\x8C\x47\xA9\xCF\x11\x8E\xE4\x00\xC0\x0C\x20\x53\x65"
#define ASF_Stream_Properties_Object_GUID "\x91\x07\xDC\xB7\xB7\xA9\xCF\x11\x8E\xE6\x00\xC0\x0C\x20\x53\x65"
#define ASF_Header_Extension_Object_GUID "\xB5\x03\xBF\x5F\x2E\xA9\xCF\x11\x8E\xE3\x00\xC0\x0C\x20\x53\x65"
#define ASF_Codec_List_Object_GUID "\x40\x52\xD1\x86\x1D\x31\xD0\x11\xA3\xA4\x00\xA0\xC9\x03\x48\xF6"
#define ASF_Script_Command_Object_GUID "\x30\x1A\xFB\x1E\x62\x0B\xD0\x11\xA3\x9B\x00\xA0\xC9\x03\x48\xF6"
#define ASF_Marker_Object_GUID "\x01\xCD\x87\xF4\x51\xA9\xCF\x11\x8E\xE6\x00\xC0\x0C\x20\x53\x65"
#define ASF_Bitrate_Mutual_Exclusion_Object_GUID "\xDC\x29\xE2\xD6\xDA\x35\xD1\x11\x90\x34\x00\xA0\xC9\x03\x49\xBE"
#define ASF_Error_Correction_Object_GUID "\x35\x26\xB2\x75\x8E\x66\xCF\x11\xA6\xD9\x00\xAA\x00\x62\xCE\x6C"
#define ASF_Content_Description_Object_GUID "\x33\x26\xB2\x75\x8E\x66\xCF\x11\xA6\xD9\x00\xAA\x00\x62\xCE\x6C"
#define ASF_Extended_Content_Description_Object_GUID "\x40\xA4\xD0\xD2\x07\xE3\xD2\x11\x97\xF0\x00\xA0\xC9\x5E\xA8\x50"
#define ASF_Content_Branding_Object_GUID "\xFA\xB3\x11\x22\x23\xBD\xD2\x11\xB4\xB7\x00\xA0\xC9\x55\xFC\x6E"
#define ASF_Stream_Bitrate_Properties_Object_GUID "\xCE\x75\xF8\x7B\x8D\x46\xD1\x11\x8D\x82\x00\x60\x97\xC9\xA2\xB2"
#define ASF_Content_Encryption_Object_GUID "\xFB\xB3\x11\x22\x23\xBD\xD2\x11\xB4\xB7\x00\xA0\xC9\x55\xFC\x6E"
#define ASF_Extended_Content_Encryption_Object_GUID "\x14\xE6\x8A\x29\x22\x26\x17\x4C\xB9\x35\xDA\xE0\x7E\xE9\x28\x9C"
#define ASF_Digital_Signature_Object_GUID "\xFC\xB3\x11\x22\x23\xBD\xD2\x11\xB4\xB7\x00\xA0\xC9\x55\xFC\x6E"
#define ASF_Padding_Object_GUID "\x74\xD4\x06\x18\xDF\xCA\x09\x45\xA4\xBA\x9A\xAB\xCB\x96\xAA\xE8"
#define ASF_Extended_Stream_Properties_Object_GUID "\xCB\xA5\xE6\x14\x72\xC6\x32\x43\x83\x99\xA9\x69\x52\x06\x5B\x5A"
#define ASF_Advanced_Mutual_Exclusion_Object_GUID "\xCF\x49\x86\xA0\x75\x47\x70\x46\x8A\x16\x6E\x35\x35\x75\x66\xCD"
#define ASF_Group_Mutual_Exclusion_Object_GUID "\x40\x5A\x46\xD1\x79\x5A\x38\x43\xB7\x1B\xE3\x6B\x8F\xD6\xC2\x49"
#define ASF_Stream_Prioritization_Object_GUID "\x5B\xD1\xFE\xD4\xD3\x88\x4F\x45\x81\xF0\xED\x5C\x45\x99\x9E\x24"
#define ASF_Bandwidth_Sharing_Object_GUID "\xE6\x09\x96\xA6\x7B\x51\xD2\x11\xB6\xAF\x00\xC0\x4F\xD9\x08\xE9"
#define ASF_Language_List_Object_GUID "\xA9\x46\x43\x7C\xE0\xEF\xFC\x4B\xB2\x29\x39\x3E\xDE\x41\x5C\x85"
#define ASF_Metadata_Object_GUID "\xEA\xCB\xF8\xC5\xAF\x5B\x77\x48\x84\x67\xAA\x8C\x44\xFA\x4C\xCA"
#define ASF_Metadata_Library_Object_GUID "\x94\x1C\x23\x44\x98\x94\xD1\x49\xA1\x41\x1D\x13\x4E\x45\x70\x54"
#define ASF_Index_Parameters_Object_GUID "\xDF\x29\xE2\xD6\xDA\x35\xD1\x11\x90\x34\x00\xA0\xC9\x03\x49\xBE"
#define ASF_Media_Object_Index_Parameters_Object_GUID "\xAD\x3B\x20\x6B\x11\x3F\xE4\x48\xAC\xA8\xD7\x61\x3D\xE2\xCF\xA7"
#define ASF_Timecode_Index_Parameters_Object_GUID "\x6D\x49\x5E\xF5\x97\x97\x5D\x4B\x8C\x8B\x60\x4D\xFE\x9B\xFB\x24"
#define ASF_Compatibility_Object_GUID "\x30\x26\xB2\x75\x8E\x66\xCF\x11\xA6\xD9\x00\xAA\x00\x62\xCE\x6C"
#define ASF_Advanced_Content_Encryption_Object_GUID "\x33\x85\x05\x43\x81\x69\xE6\x49\x9B\x74\xAD\x12\xCB\x86\xD5\x8C"
#define ASF_Audio_Media_GUID "\x40\x9E\x69\xF8\x4D\x5B\xCF\x11\xA8\xFD\x00\x80\x5F\x5C\x44\x2B"
#define ASF_Video_Media_GUID "\xC0\xEF\x19\xBC\x4D\x5B\xCF\x11\xA8\xFD\x00\x80\x5F\x5C\x44\x2B"
#define ASF_Command_Media_GUID "\xC0\xCF\xDA\x59\xE6\x59\xD0\x11\xA3\xAC\x00\xA0\xC9\x03\x48\xF6"
#define ASF_JFIF_Media_GUID "\x00\xE1\x1B\xB6\x4E\x5B\xCF\x11\xA8\xFD\x00\x80\x5F\x5C\x44\x2B"
#define ASF_Degradable_JPEG_Media_GUID "\xE0\x7D\x90\x35\x15\xE4\xCF\x11\xA9\x17\x00\x80\x5F\x5C\x44\x2B"
#define ASF_File_Transfer_Media_GUID "\x2C\x22\xBD\x91\x1C\xF2\x7A\x49\x8B\x6D\x5A\xA8\x6B\xFC\x01\x85"
#define ASF_Binary_Media_GUID "\xE2\x65\xFB\x3A\xEF\x47\xF2\x40\xAC\x2C\x70\xA9\x0D\x71\xD3\x43"
#define ASF_Web_Stream_Media_Subtype_GUID "\xD4\x57\x62\x77\x27\xC6\xCB\x41\x8F\x81\x7A\xC7\xFF\x1C\x40\xCC"
#define ASF_Web_Stream_Format_GUID "\x13\x6B\x1E\xDA\x59\x83\x50\x40\xB3\x98\x38\x8E\x96\x5B\xF0\x0C"
#define ASF_No_Error_Correction_GUID "\x00\x57\xFB\x20\x55\x5B\xCF\x11\xA8\xFD\x00\x80\x5F\x5C\x44\x2B"
#define ASF_Audio_Spread_GUID "\x50\xCD\xC3\xBF\x8F\x61\xCF\x11\x8B\xB2\x00\xAA\x00\xB4\xE2\x20"
#define ASF_Reserved_1_GUID "\x11\xD2\xD3\xAB\xBA\xA9\xcf\x11\x8E\xE6\x00\xC0\x0C\x20\x53\x65"
#define ASF_Content_Encryption_System_Windows_Media_DRM_Network_Devices_GUID "\xB6\x9B\x07\x7A\xA4\xDA\x12\x4e\xA5\xCA\x91\xD3\x8D\xC1\x1A\x8D"
#define ASF_Reserved_2_GUID "\x41\x52\xD1\x86\x1D\x31\xD0\x11\xA3\xA4\x00\xA0\xC9\x03\x48\xF6"
#define ASF_Reserved_3_GUID "\xE3\xCB\x1A\x4B\x0B\x10\xD0\x11\xA3\x9B\x00\xA0\xC9\x03\x48\xF6"
#define ASF_Reserved_4_GUID "\x20\xDB\xFE\x4C\xF6\x75\xCF\x11\x9C\x0F\x00\xA0\xC9\x03\x49\xCB"
#define ASF_Mutex_Language_GUID "\x00\x2A\xE2\xD6\xDA\x35\xD1\x11\x90\x34\x00\xA0\xC9\x03\x49\xBE"
#define ASF_Mutex_Bitrate_GUID "\x01\x2A\xE2\xD6\xDA\x35\xD1\x11\x90\x34\x00\xA0\xC9\x03\x49\xBE"
#define ASF_Mutex_Unknown_GUID "\x02\x2A\xE2\xD6\xDA\x35\xD1\x11\x90\x34\x00\xA0\xC9\x03\x49\xBE"
#define ASF_Bandwidth_Sharing_Exclusive_GUID "\xAA\x60\x60\xAF\x97\x51\xD2\x11\xB6\xAF\x00\xC0\x4F\xD9\x08\xE9"
#define ASF_Bandwidth_Sharing_Partial_GUID "\xAB\x60\x60\xAF\x97\x51\xD2\x11\xB6\xAF\x00\xC0\x4F\xD9\x08\xE9"
#define ASF_Payload_Extension_System_Timecode_GUID "\xEC\x95\x95\x39\x67\x86\x2D\x4E\x8F\xDB\x98\x81\x4C\xE7\x6C\x1E"
#define ASF_Payload_Extension_System_File_Name_GUID "\x0E\xEC\x65\xE1\xED\x19\xD7\x45\xB4\xA7\x25\xCB\xD1\xE2\x8E\x9B"
#define ASF_Payload_Extension_System_Content_Type_GUID "\x20\xDC\x90\xD5\xBC\x07\x6C\x43\x9C\xF7\xF3\xBB\xFB\xF1\xA4\xDC"
#define ASF_Payload_Extension_System_Pixel_Aspect_Ratio_GUID "\x54\xE5\x1E\x1B\xEA\xF9\xC8\x4B\x82\x1A\x37\x6B\x74\xE4\xC4\xB8"
#define ASF_Payload_Extension_System_Sample_Duration_GUID "\x50\x94\xBD\xC6\x7F\x86\x07\x49\x83\xA3\xC7\x79\x21\xB7\x33\xAD"
#define ASF_Payload_Extension_System_Encryption_Sample_ID_GUID "\x4E\xB8\x98\x66\xFA\x0A\x30\x43\xAE\xB2\x1C\x0A\x98\xD7\xA4\x4D"

int asf_isfile(const uint8_t *data, size_t input_len, size_t *lengthptr);

#endif /* AUDIOEXTRACT_ASF_H__ */