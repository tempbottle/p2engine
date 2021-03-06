//
// mime_types.cpp
// ~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include "p2engine/http/mime_types.hpp"
#include "p2engine/push_warning_option.hpp"
#include <cstring>
#include "p2engine/pop_warning_option.hpp"

#ifdef WINDOWS_OS
#	ifndef strcasecmp
#		define  strcasecmp _strcmpi
#	endif
#endif

namespace http { namespace http { namespace mime_types {

	typedef struct _mime_type
	{
		const char* ext_name;
		const char* mime_type;
	} MimeType;

	typedef struct _mime_ext_type
	{
		const char* mime_type;
		const char* ext_name;
	} MimeExtType;

	static const MimeType _mime_type_table[] =
	{
		{ "123", "application/vnd.lotus-1-2-3" },
		{ "3g2", "video/3gpp2" },
		{ "3gp", "video/3gpp" },
		{ "3gp2", "video/3gpp2" },
		{ "3gpp", "video/3gpp" },
		{ "7z", "application/x-7z-compressed" },
		{ "aab", "application/x-authoware-bin" },
		{ "aac", "audio/vnd.dlna.adts" },
		{ "aam", "application/x-authoware-map" },
		{ "aas", "application/x-authoware-seg" },
		{ "acrobatsecuritysettings", "application/vnd.adobe.acrobat-security-settings" },
		{ "addin", "text/xml" },
		{ "adt", "audio/vnd.dlna.adts" },
		{ "adts", "audio/vnd.dlna.adts" },
		{ "ai", "application/postscript" },
		{ "aif", "audio/aiff" },
		{ "aifc", "audio/aiff" },
		{ "aiff", "audio/aiff" },
		{ "als", "audio/x-alpha5" },
		{ "amc", "application/x-mpeg" },
		{ "ani", "application/octet-stream" },
		{ "application", "application/x-ms-application" },
		{ "asc", "text/plain" },
		{ "asd", "application/astound" },
		{ "asf", "video/x-ms-asf" },
		{ "asm", "text/plain" },
		{ "asn", "application/astound" },
		{ "asp", "application/x-asap" },
		{ "asx", "video/x-ms-asf" },
		{ "au", "audio/basic" },
		{ "avb", "application/octet-stream" },
		{ "avi", "video/avi" },
		{ "awb", "audio/amr-wb" },
		{ "bcpio", "application/x-bcpio" },
		{ "bin", "application/octet-stream" },
		{ "bld", "application/bld" },
		{ "bld2", "application/bld2" },
		{ "bmp", "image/bmp" },
		{ "bpk", "application/octet-stream" },
		{ "bz2", "application/x-bzip2" },
		{ "c", "text/plain" },
		{ "cal", "image/x-cals" },
		{ "cat", "application/vnd.ms-pki.seccat" },
		{ "cc", "text/plain" },
		{ "ccn", "application/x-cnc" },
		{ "cco", "application/x-cocoa" },
		{ "cdf", "application/x-netcdf" },
		{ "cer", "application/x-x509-ca-cert" },
		{ "cgi", "magnus-internal/cgi" },
		{ "chat", "application/x-chat" },
		{ "class", "application/octet-stream" },
		{ "clp", "application/x-msclip" },
		{ "cmx", "application/x-cmx" },
		{ "co", "application/x-cult3d-object" },
		{ "cod", "text/plain" },
		{ "config", "application/xml" },
		{ "contact", "text/x-ms-contact" },
		{ "cpio", "application/x-cpio" },
		{ "cpp", "text/plain" },
		{ "cpt", "application/mac-compactpro" },
		{ "crd", "application/x-mscardfile" },
		{ "crl", "application/pkix-crl" },
		{ "crt", "application/x-x509-ca-cert" },
		{ "csh", "application/x-csh" },
		{ "csm", "chemical/x-csml" },
		{ "csml", "chemical/x-csml" },
		{ "css", "text/css" },
		{ "csv", "application/vnd.ms-excel" },
		{ "cur", "text/plain" },
		{ "cxx", "text/plain" },
		{ "datasource", "application/xml" },
		{ "dcm", "x-lml/x-evm" },
		{ "dcr", "application/x-director" },
		{ "dcx", "image/x-dcx" },
		{ "def", "text/plain" },
		{ "der", "application/x-x509-ca-cert" },
		{ "dhtml", "text/html" },
		{ "dib", "image/bmp" },
		{ "dir", "application/x-director" },
		{ "dll", "application/x-msdownload" },
		{ "dmg", "application/octet-stream" },
		{ "dms", "application/octet-stream" },
		{ "doc", "application/msword" },
		{ "docm", "application/vnd.ms-word.document.macroenabled.12" },
		{ "docx", "application/vnd.openxmlformats-officedocument.wordprocessingml.document" },
		{ "dot", "application/msword" },
		{ "dotm", "application/vnd.ms-word.template.macroenabled.12" },
		{ "dotx", "application/vnd.openxmlformats-officedocument.wordprocessingml.template" },
		{ "dsp", "text/plain" },
		{ "dsw", "text/plain" },
		{ "dtd", "application/xml-dtd" },
		{ "dvi", "application/x-dvi" },
		{ "dwf", "drawing/x-dwf" },
		{ "dwfx", "model/vnd.dwfx+xps" },
		{ "dwg", "application/x-autocad" },
		{ "dxf", "application/x-autocad" },
		{ "dxr", "application/x-director" },
		{ "easmx", "model/vnd.easmx+xps" },
		{ "ebk", "application/x-expandedbook" },
		{ "edrwx", "model/vnd.edrwx+xps" },
		{ "emb", "chemical/x-embl-dl-nucleotide" },
		{ "embl", "chemical/x-embl-dl-nucleotide" },
		{ "eml", "message/rfc822" },
		{ "eprtx", "model/vnd.eprtx+xps" },
		{ "eps", "application/postscript" },
		{ "eri", "image/x-eri" },
		{ "es", "audio/echospeech" },
		{ "esl", "audio/echospeech" },
		{ "etc", "application/x-earthtime" },
		{ "etx", "text/x-setext" },
		{ "evm", "x-lml/x-evm" },
		{ "evy", "application/x-envoy" },
		{ "exe", "application/x-msdownload" },
		{ "fdf", "application/vnd.fdf" },
		{ "fh4", "image/x-freehand" },
		{ "fh5", "image/x-freehand" },
		{ "fhc", "image/x-freehand" },
		{ "fif", "application/fractals" },
		{ "filters", "application/xml" },
		{ "fm", "application/x-maker" },
		{ "fpx", "image/x-fpx" },
		{ "fvi", "video/isivideo" },
		{ "gau", "chemical/x-gaussian-input" },
		{ "gca", "application/x-gca-compressed" },
		{ "gdb", "x-lml/x-gdb" },
		{ "gif", "image/gif" },
		{ "gps", "application/x-gps" },
		{ "group", "text/x-ms-group" },
		{ "gtar", "application/x-gtar" },
		{ "gz", "application/x-gzip" },
		{ "h", "text/plain" },
		{ "hdf", "application/x-hdf" },
		{ "hdm", "text/x-hdml" },
		{ "hdml", "text/x-hdml" },
		{ "hlp", "application/winhlp" },
		{ "hpp", "text/plain" },
		{ "hqx", "application/mac-binhex40" },
		{ "hta", "application/hta" },
		{ "htc", "text/x-component" },
		{ "htm", "text/html" },
		{ "html", "text/html" },
		{ "hts", "text/html" },
		{ "hxa", "application/xml" },
		{ "hxc", "application/xml" },
		{ "hxd", "application/octet-stream" },
		{ "hxe", "application/xml" },
		{ "hxf", "application/xml" },
		{ "hxh", "application/octet-stream" },
		{ "hxi", "application/octet-stream" },
		{ "hxk", "application/xml" },
		{ "hxq", "application/octet-stream" },
		{ "hxr", "application/octet-stream" },
		{ "hxs", "application/octet-stream" },
		{ "hxt", "application/xml" },
		{ "hxv", "application/xml" },
		{ "hxw", "application/octet-stream" },
		{ "hxx", "text/plain" },
		{ "i", "text/plain" },
		{ "ice", "x-conference/x-cooltalk" },
		{ "ico", "image/x-icon" },
		{ "idl", "text/plain" },
		{ "ief", "image/ief" },
		{ "ifm", "image/gif" },
		{ "ifs", "image/ifs" },
		{ "imy", "audio/melody" },
		{ "inc", "text/plain" },
		{ "inl", "text/plain" },
		{ "ins", "application/x-net-install" },
		{ "ips", "application/x-ipscript" },
		{ "ipx", "application/x-ipix" },
		{ "iqy", "text/x-ms-iqy" },
		{ "it", "audio/x-mod" },
		{ "itz", "audio/x-mod" },
		{ "ivr", "i-world/i-vrml" },
		{ "j2k", "image/j2k" },
		{ "jad", "text/vnd.sun.j2me.app-descriptor" },
		{ "jam", "application/x-jam" },
		{ "jar", "application/java-archive" },
		{ "jfif", "image/jpeg" },
		{ "jnlp", "application/x-java-jnlp-file" },
		{ "jpe", "image/jpeg" },
		{ "jpeg", "image/jpeg" },
		{ "jpg", "image/jpeg" },
		{ "jpz", "image/jpeg" },
		{ "js", "application/x-javascript" },
		{ "jtx", "application/x-jtx+xps" },
		{ "jwc", "application/jwc" },
		{ "kjx", "application/x-kjx" },
		{ "lak", "x-lml/x-lak" },
		{ "latex", "application/x-latex" },
		{ "lcc", "application/fastman" },
		{ "lcl", "application/x-digitalloca" },
		{ "lcr", "application/x-digitalloca" },
		{ "lgh", "application/lgh" },
		{ "lha", "application/octet-stream" },
		{ "library-ms", "application/windows-library+xml" },
		{ "lml", "x-lml/x-lml" },
		{ "lmlpack", "x-lml/x-lmlpack" },
		{ "lsf", "video/x-ms-asf" },
		{ "lst", "text/plain" },
		{ "lsx", "video/x-ms-asf" },
		{ "lzh", "application/x-lzh" },
		{ "m13", "application/x-msmediaview" },
		{ "m14", "application/x-msmediaview" },
		{ "m15", "audio/x-mod" },
		{ "m1v", "video/mpeg" },
		{ "m2t", "video/vnd.dlna.mpeg-tts" },
		{ "m2ts", "video/vnd.dlna.mpeg-tts" },
		{ "m2v", "video/mpeg" },
		{ "m3u", "audio/x-mpegurl" },
		{ "m3url", "audio/x-mpegurl" },
		{ "m4a", "audio/mp4" },
		{ "m4v", "video/mp4" },
		{ "ma1", "audio/ma1" },
		{ "ma2", "audio/ma2" },
		{ "ma3", "audio/ma3" },
		{ "ma5", "audio/ma5" },
		{ "mak", "text/plain" },
		{ "man", "application/x-troff-man" },
		{ "map", "text/plain" },
		{ "mbd", "application/mbedlet" },
		{ "mct", "application/x-mascot" },
		{ "mdb", "application/x-msaccess" },
		{ "mdp", "text/plain" },
		{ "mdz", "audio/x-mod" },
		{ "me", "application/x-troff-me" },
		{ "mel", "text/x-vmel" },
		{ "mfp", "application/x-shockwave-flash" },
		{ "mht", "message/rfc822" },
		{ "mhtml", "message/rfc822" },
		{ "mi", "application/x-mif" },
		{ "mid", "audio/mid" },
		{ "midi", "audio/mid" },
		{ "mif", "application/x-mif" },
		{ "mil", "image/x-cals" },
		{ "mio", "audio/x-mio" },
		{ "mk", "text/plain" },
		{ "mmf", "application/x-skt-lbs" },
		{ "mng", "video/x-mng" },
		{ "mny", "application/x-msmoney" },
		{ "moc", "application/x-mocha" },
		{ "mocha", "application/x-mocha" },
		{ "mod", "video/mpeg" },
		{ "mof", "application/x-yumekara" },
		{ "mol", "chemical/x-mdl-molfile" },
		{ "mop", "chemical/x-mopac-input" },
		{ "mov", "video/quicktime" },
		{ "movie", "video/x-sgi-movie" },
		{ "mp2", "audio/mpeg" },
		{ "mp2v", "video/mpeg" },
		{ "mp3", "audio/mpeg" },
		{ "mp4", "video/mp4" },
		{ "mp4v", "video/mp4" },
		{ "mpa", "video/mpeg" },
		{ "mpc", "application/vnd.mpohun.certificate" },
		{ "mpe", "video/mpeg" },
		{ "mpeg", "video/mpeg" },
		{ "mpg", "video/mpeg" },
		{ "mpg4", "video/mp4" },
		{ "mpga", "audio/mpeg" },
		{ "mpn", "application/vnd.mophun.application" },
		{ "mpp", "application/vnd.ms-project" },
		{ "mps", "application/x-mapserver" },
		{ "mpv2", "video/mpeg" },
		{ "mrl", "text/x-mrml" },
		{ "mrm", "application/x-mrm" },
		{ "ms", "application/x-troff-ms" },
		{ "mts", "video/vnd.dlna.mpeg-tts" },
		{ "mtx", "application/metastream" },
		{ "mtz", "application/metastream" },
		{ "mzv", "application/metastream" },
		{ "nar", "application/zip" },
		{ "nbmp", "image/nbmp" },
		{ "nc", "application/x-netcdf" },
		{ "ndb", "x-lml/x-ndb" },
		{ "ndwn", "application/ndwn" },
		{ "nif", "application/x-nif" },
		{ "nmz", "application/x-scream" },
		{ "nokia-op-logo", "image/vnd.nok-oplogo-color" },
		{ "npx", "application/x-netfpx" },
		{ "nsnd", "audio/nsnd" },
		{ "nva", "application/x-neva1" },
		{ "oda", "application/oda" },
		{ "odc", "text/x-ms-odc" },
		{ "odh", "text/plain" },
		{ "odl", "text/plain" },
		{ "odp", "application/vnd.oasis.opendocument.presentation" },
		{ "ods", "application/vnd.oasis.opendocument.spreadsheet" },
		{ "odt", "application/vnd.oasis.opendocument.text" },
		{ "oom", "application/x-atlasmate-plugin" },
		{ "osdx", "application/opensearchdescription+xml" },
		{ "p10", "application/pkcs10" },
		{ "p12", "application/x-pkcs12" },
		{ "p7b", "application/x-pkcs7-certificates" },
		{ "p7c", "application/pkcs7-mime" },
		{ "p7m", "application/pkcs7-mime" },
		{ "p7r", "application/x-pkcs7-certreqresp" },
		{ "p7s", "application/pkcs7-signature" },
		{ "pac", "audio/x-pac" },
		{ "pae", "audio/x-epac" },
		{ "pan", "application/x-pan" },
		{ "pbm", "image/x-portable-bitmap" },
		{ "pcx", "image/x-pcx" },
		{ "pda", "image/x-pda" },
		{ "pdb", "chemical/x-pdb" },
		{ "pdf", "application/pdf" },
		{ "pdfxml", "application/vnd.adobe.pdfxml" },
		{ "pdx", "application/vnd.adobe.pdx" },
		{ "pfr", "application/font-tdpfr" },
		{ "pfx", "application/x-pkcs12" },
		{ "pgm", "image/x-portable-graymap" },
		{ "pict", "image/x-pict" },
		{ "pko", "application/vnd.ms-pki.pko" },
		{ "pm", "application/x-perl" },
		{ "pmd", "audio/pmd" },
		{ "png", "image/png" },
		{ "pnm", "image/x-portable-anymap" },
		{ "pnz", "image/png" },
		{ "pot", "application/vnd.ms-powerpoint" },
		{ "potm", "application/vnd.ms-powerpoint.template.macroenabled.12" },
		{ "potx", "application/vnd.openxmlformats-officedocument.presentationml.template" },
		{ "ppa", "application/vnd.ms-powerpoint" },
		{ "ppam", "application/vnd.ms-powerpoint.addin.macroenabled.12" },
		{ "ppm", "image/x-portable-pixmap" },
		{ "pps", "application/vnd.ms-powerpoint" },
		{ "ppsm", "application/vnd.ms-powerpoint.slideshow.macroenabled.12" },
		{ "ppsx", "application/vnd.openxmlformats-officedocument.presentationml.slideshow" },
		{ "ppt", "application/vnd.ms-powerpoint" },
		{ "pptm", "application/vnd.ms-powerpoint.presentation.macroenabled.12" },
		{ "pptx", "application/vnd.openxmlformats-officedocument.presentationml.presentation" },
		{ "pqf", "application/x-cprplayer" },
		{ "pqi", "application/cprplayer" },
		{ "prc", "application/x-prc" },
		{ "prf", "application/pics-rules" },
		{ "proxy", "application/x-ns-proxy-autoconfig" },
		{ "ps", "application/postscript" },
		{ "psc1", "application/powershell" },
		{ "ptlk", "application/listenup" },
		{ "pub", "application/x-mspublisher" },
		{ "pvx", "video/x-pv-pvx" },
		{ "pwz", "application/vnd.ms-powerpoint" },
		{ "qcp", "audio/vnd.qcelp" },
		{ "qt", "video/quicktime" },
		{ "qti", "image/x-quicktime" },
		{ "qtif", "image/x-quicktime" },
		{ "r3t", "text/vnd.rn-realtext3d" },
		{ "ra", "audio/x-pn-realaudio" },
		{ "ram", "audio/x-pn-realaudio" },
		{ "rar", "application/x-rar-compressed" },
		{ "ras", "image/x-cmu-raster" },
		{ "rat", "application/rat-file" },
		{ "rdf", "application/rdf+xml" },
		{ "resx", "application/xml" },
		{ "rf", "image/vnd.rn-realflash" },
		{ "rgb", "image/x-rgb" },
		{ "rgs", "text/plain" },
		{ "rlf", "application/x-richlink" },
		{ "rm", "audio/x-pn-realaudio" },
		{ "rmf", "audio/x-rmf" },
		{ "rmi", "audio/mid" },
		{ "rmm", "audio/x-pn-realaudio" },
		{ "rmvb", "audio/x-pn-realaudio" },
		{ "rnx", "application/vnd.rn-realplayer" },
		{ "roff", "application/x-troff" },
		{ "rp", "image/vnd.rn-realpix" },
		{ "rpm", "audio/x-pn-realaudio-plugin" },
		{ "rqy", "text/x-ms-rqy" },
		{ "rt", "text/vnd.rn-realtext" },
		{ "rte", "x-lml/x-gps" },
		{ "rtf", "application/msword" },
		{ "rtg", "application/metastream" },
		{ "rtx", "text/richtext" },
		{ "rv", "video/vnd.rn-realvideo" },
		{ "rwc", "application/x-rogerwilco" },
		{ "s", "text/plain" },
		{ "s3m", "audio/x-mod" },
		{ "s3z", "audio/x-mod" },
		{ "sca", "application/x-supercard" },
		{ "scd", "application/x-msschedule" },
		{ "sct", "text/scriptlet" },
		{ "sdf", "application/e-score" },
		{ "sea", "application/x-stuffit" },
		{ "searchconnector-ms", "application/windows-search-connector+xml" },
		{ "settings", "application/xml" },
		{ "sgm", "text/x-sgml" },
		{ "sgml", "text/x-sgml" },
		{ "sh", "application/x-sh" },
		{ "shar", "application/x-shar" },
		{ "shtml", "text/html" },
		{ "shw", "application/presentations" },
		{ "si6", "image/si6" },
		{ "si7", "image/vnd.stiwap.sis" },
		{ "si9", "image/vnd.lgtwap.sis" },
		{ "sis", "image/sis" },
		{ "sit", "application/x-stuffit" },
		{ "skd", "application/x-koan" },
		{ "skm", "application/x-koan" },
		{ "skp", "application/x-koan" },
		{ "skt", "application/x-koan" },
		{ "skype", "application/x-skype" },
		{ "slc", "application/x-salsa" },
		{ "sldm", "application/vnd.ms-powerpoint.slide.macroenabled.12" },
		{ "sldx", "application/vnd.openxmlformats-officedocument.presentationml.slide" },
		{ "slk", "application/vnd.ms-excel" },
		{ "sln", "text/plain" },
		{ "slupkg-ms", "application/x-ms-license" },
		{ "smd", "audio/x-smd" },
		{ "smi", "application/smil" },
		{ "smil", "application/smil" },
		{ "smp", "application/studiom" },
		{ "smz", "audio/x-smd" },
		{ "snd", "audio/basic" },
		{ "sol", "text/plain" },
		{ "sor", "text/plain" },
		{ "spc", "application/x-pkcs7-certificates" },
		{ "spl", "application/futuresplash" },
		{ "spr", "application/x-sprite" },
		{ "sprite", "application/x-sprite" },
		{ "spt", "application/x-spt" },
		{ "src", "application/x-wais-source" },
		{ "srf", "text/plain" },
		{ "sst", "application/vnd.ms-pki.certstore" },
		{ "stk", "application/hyperstudio" },
		{ "stl", "application/vnd.ms-pki.stl" },
		{ "stm", "audio/x-mod" },
		{ "sv4cpio", "application/x-sv4cpio" },
		{ "sv4crc", "application/x-sv4crc" },
		{ "svf", "image/vnd" },
		{ "svg", "image/svg-xml" },
		{ "svh", "image/svh" },
		{ "svr", "x-world/x-svr" },
		{ "swf", "application/x-shockwave-flash" },
		{ "swfl", "application/x-shockwave-flash" },
		{ "t", "application/x-troff" },
		{ "tad", "application/octet-stream" },
		{ "talk", "text/x-speech" },
		{ "tar", "application/x-tar" },
		{ "taz", "application/x-tar" },
		{ "tbp", "application/x-timbuktu" },
		{ "tbt", "application/x-timbuktu" },
		{ "tcl", "application/x-tcl" },
		{ "tex", "application/x-tex" },
		{ "texi", "application/x-texinfo" },
		{ "texinfo", "application/x-texinfo" },
		{ "tgz", "application/x-tar" },
		{ "thm", "application/vnd.eri.thm" },
		{ "thmx", "application/vnd.ms-officetheme" },
		{ "tif", "image/tiff" },
		{ "tiff", "image/tiff" },
		{ "tki", "application/x-tkined" },
		{ "tkined", "application/x-tkined" },
		{ "tlh", "text/plain" },
		{ "tli", "text/plain" },
		{ "toc", "application/toc" },
		{ "toy", "image/toy" },
		{ "tr", "application/x-troff" },
		{ "trk", "x-lml/x-gps" },
		{ "trm", "application/x-msterminal" },
		{ "ts", "video/vnd.dlna.mpeg-tts" },
		{ "tsi", "audio/tsplayer" },
		{ "tsp", "application/dsptype" },
		{ "tsv", "text/tab-separated-values" },
		{ "ttf", "application/octet-stream" },
		{ "tts", "video/vnd.dlna.mpeg-tts" },
		{ "ttz", "application/t-time" },
		{ "txt", "text/plain" },
		{ "ult", "audio/x-mod" },
		{ "ustar", "application/x-ustar" },
		{ "uu", "application/x-uuencode" },
		{ "uue", "application/x-uuencode" },
		{ "vcd", "application/x-cdlink" },
		{ "vcf", "text/x-vcard" },
		{ "vcproj", "application/xml" },
		{ "vcxproj", "application/xml" },
		{ "vdo", "video/vdo" },
		{ "vdx", "application/vnd.ms-visio.viewer" },
		{ "vib", "audio/vib" },
		{ "viv", "video/vivo" },
		{ "vivo", "video/vivo" },
		{ "vmd", "application/vocaltec-media-desc" },
		{ "vmf", "application/vocaltec-media-file" },
		{ "vmi", "application/x-dreamcast-vms-info" },
		{ "vms", "application/x-dreamcast-vms" },
		{ "vox", "audio/voxware" },
		{ "vqe", "audio/x-twinvq-plugin" },
		{ "vqf", "audio/x-twinvq" },
		{ "vql", "audio/x-twinvq" },
		{ "vre", "x-world/x-vream" },
		{ "vrml", "x-world/x-vrml" },
		{ "vrt", "x-world/x-vrt" },
		{ "vrw", "x-world/x-vream" },
		{ "vscontent", "application/xml" },
		{ "vsd", "application/vnd.ms-visio.viewer" },
		{ "vsi", "application/ms-vsi" },
		{ "vsix", "application/vsix" },
		{ "vsixlangpack", "text/xml" },
		{ "vsixmanifest", "text/xml" },
		{ "vss", "application/vnd.ms-visio.viewer" },
		{ "vssettings", "text/xml" },
		{ "vst", "application/vnd.ms-visio.viewer" },
		{ "vstemplate", "text/xml" },
		{ "vsto", "application/x-ms-vsto" },
		{ "vsx", "application/vnd.ms-visio.viewer" },
		{ "vts", "workbook/formulaone" },
		{ "vtx", "application/vnd.ms-visio.viewer" },
		{ "wav", "audio/wav" },
		{ "wax", "audio/x-ms-wax" },
		{ "wbk", "application/msword" },
		{ "wbmp", "image/vnd.wap.wbmp" },
		{ "wdp", "image/vnd.ms-photo" },
		{ "web", "application/vnd.xara" },
		{ "wi", "image/wavelet" },
		{ "wis", "application/x-installshield" },
		{ "wiz", "application/msword" },
		{ "wm", "video/x-ms-wm" },
		{ "wma", "audio/x-ms-wma" },
		{ "wmd", "application/x-ms-wmd" },
		{ "wmf", "application/x-msmetafile" },
		{ "wml", "text/vnd.wap.wml" },
		{ "wmlc", "application/vnd.wap.wmlc" },
		{ "wmls", "text/vnd.wap.wmlscript" },
		{ "wmlsc", "application/vnd.wap.wmlscriptc" },
		{ "wmlscript", "text/vnd.wap.wmlscript" },
		{ "wmv", "video/x-ms-wmv" },
		{ "wmx", "video/x-ms-wmx" },
		{ "wmz", "application/x-ms-wmz" },
		{ "wpl", "application/vnd.ms-wpl" },
		{ "wpng", "image/x-up-wpng" },
		{ "wpt", "x-lml/x-gps" },
		{ "wri", "application/x-mswrite" },
		{ "wrl", "x-world/x-vrml" },
		{ "wrz", "x-world/x-vrml" },
		{ "ws", "text/vnd.wap.wmlscript" },
		{ "wsc", "text/scriptlet" },
		{ "wsdl", "application/xml" },
		{ "wv", "video/wavelet" },
		{ "wvx", "video/x-ms-wvx" },
		{ "wxl", "application/x-wxl" },
		{ "x-gzip", "application/x-gzip" },
		{ "xaml", "application/xaml+xml" },
		{ "xar", "application/vnd.xara" },
		{ "xbap", "application/x-ms-xbap" },
		{ "xbm", "image/x-xbitmap" },
		{ "xdm", "application/x-xdma" },
		{ "xdma", "application/x-xdma" },
		{ "xdp", "application/vnd.adobe.xdp+xml" },
		{ "xdr", "application/xml" },
		{ "xdw", "application/vnd.fujixerox.docuworks" },
		{ "xfdf", "application/vnd.adobe.xfdf" },
		{ "xht", "application/xhtml+xml" },
		{ "xhtm", "application/xhtml+xml" },
		{ "xhtml", "application/xhtml+xml" },
		{ "xla", "application/vnd.ms-excel" },
		{ "xlam", "application/vnd.ms-excel.addin.macroenabled.12" },
		{ "xlc", "application/vnd.ms-excel" },
		{ "xld", "application/vnd.ms-excel" },
		{ "xlk", "application/vnd.ms-excel" },
		{ "xll", "application/vnd.ms-excel" },
		{ "xlm", "application/vnd.ms-excel" },
		{ "xls", "application/vnd.ms-excel" },
		{ "xlsb", "application/vnd.ms-excel.sheet.binary.macroenabled.12" },
		{ "xlsm", "application/vnd.ms-excel.sheet.macroenabled.12" },
		{ "xlsx", "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet" },
		{ "xlt", "application/vnd.ms-excel" },
		{ "xltm", "application/vnd.ms-excel.template.macroenabled.12" },
		{ "xltx", "application/vnd.openxmlformats-officedocument.spreadsheetml.template" },
		{ "xlw", "application/vnd.ms-excel" },
		{ "xm", "audio/x-mod" },
		{ "xml", "text/xml" },
		{ "xmz", "audio/x-mod" },
		{ "xpi", "application/x-xpinstall" },
		{ "xpm", "image/x-xpixmap" },
		{ "xps", "application/vnd.ms-xpsdocument" },
		{ "xrm-ms", "text/xml" },
		{ "xsit", "text/xml" },
		{ "xsl", "text/xml" },
		{ "xslt", "application/xml" },
		{ "xul", "text/xul" },
		{ "xwd", "image/x-xwindowdump" },
		{ "xyz", "chemical/x-pdb" },
		{ "yz1", "application/x-yz1" },
		{ "z", "application/x-compress" },
		{ "zac", "application/x-zaurus-zac" },
		{ "zip", "application/zip" },
		{ NULL, NULL }
	};

	static const MimeExtType _mime_ext_table[] =
	{
		{ "application/astound", "asd" },
		{ "application/bld", "bld" },
		{ "application/bld2", "bld2" },
		{ "application/cprplayer", "pqi" },
		{ "application/dsptype", "tsp" },
		{ "application/e-score", "sdf" },
		{ "application/fastman", "lcc" },
		{ "application/font-tdpfr", "pfr" },
		{ "application/fractals", "fif" },
		{ "application/futuresplash", "spl" },
		{ "application/hta", "hta" },
		{ "application/hyperstudio", "stk" },
		{ "application/java-archive", "jar" },
		{ "application/jwc", "jwc" },
		{ "application/lgh", "lgh" },
		{ "application/listenup", "ptlk" },
		{ "application/mac-binhex40", "hqx" },
		{ "application/mac-compactpro", "cpt" },
		{ "application/mbedlet", "mbd" },
		{ "application/metastream", "mtx" },
		{ "application/ms-vsi", "vsi" },
		{ "application/msword", "doc" },
		{ "application/ndwn", "ndwn" },
		{ "application/octet-stream", "bin" },
		{ "application/oda", "oda" },
		{ "application/opensearchdescription+xml", "osdx" },
		{ "application/pdf", "pdf" },
		{ "application/pics-rules", "prf" },
		{ "application/pkcs10", "p10" },
		{ "application/pkcs7-mime", "p7m" },
		{ "application/pkcs7-signature", "p7s" },
		{ "application/pkix-crl", "crl" },
		{ "application/postscript", "ai" },
		{ "application/powershell", "psc1" },
		{ "application/presentations", "shw" },
		{ "application/rat-file", "rat" },
		{ "application/rdf+xml", "rdf" },
		{ "application/smil", "smil" },
		{ "application/studiom", "smp" },
		{ "application/t-time", "ttz" },
		{ "application/toc", "toc" },
		{ "application/vnd.adobe.acrobat-security-settings", "acrobatsecuritysettings" },
		{ "application/vnd.adobe.pdfxml", "pdfxml" },
		{ "application/vnd.adobe.pdx", "pdx" },
		{ "application/vnd.adobe.xdp+xml", "xdp" },
		{ "application/vnd.adobe.xfdf", "xfdf" },
		{ "application/vnd.eri.thm", "thm" },
		{ "application/vnd.fdf", "fdf" },
		{ "application/vnd.fujixerox.docuworks", "xdw" },
		{ "application/vnd.lotus-1-2-3", "123" },
		{ "application/vnd.mophun.application", "mpn" },
		{ "application/vnd.mpohun.certificate", "mpc" },
		{ "application/vnd.ms-excel", "xls" },
		{ "application/vnd.ms-excel.addin.macroenabled.12", "xlam" },
		{ "application/vnd.ms-excel.sheet.binary.macroenabled.12", "xlsb" },
		{ "application/vnd.ms-excel.sheet.macroenabled.12", "xlsm" },
		{ "application/vnd.ms-excel.template.macroenabled.12", "xltm" },
		{ "application/vnd.ms-officetheme", "thmx" },
		{ "application/vnd.ms-pki.certstore", "sst" },
		{ "application/vnd.ms-pki.pko", "pko" },
		{ "application/vnd.ms-pki.seccat", "cat" },
		{ "application/vnd.ms-pki.stl", "stl" },
		{ "application/vnd.ms-powerpoint", "ppt" },
		{ "application/vnd.ms-powerpoint.addin.macroenabled.12", "ppam" },
		{ "application/vnd.ms-powerpoint.presentation.macroenabled.12", "pptm" },
		{ "application/vnd.ms-powerpoint.slide.macroenabled.12", "sldm" },
		{ "application/vnd.ms-powerpoint.slideshow.macroenabled.12", "ppsm" },
		{ "application/vnd.ms-powerpoint.template.macroenabled.12", "potm" },
		{ "application/vnd.ms-project", "mpp" },
		{ "application/vnd.ms-visio.viewer", "vsd" },
		{ "application/vnd.ms-word.document.macroenabled.12", "docm" },
		{ "application/vnd.ms-word.template.macroenabled.12", "dotm" },
		{ "application/vnd.ms-wpl", "wpl" },
		{ "application/vnd.ms-xpsdocument", "xps" },
		{ "application/vnd.oasis.opendocument.presentation", "odp" },
		{ "application/vnd.oasis.opendocument.spreadsheet", "ods" },
		{ "application/vnd.oasis.opendocument.text", "odt" },
		{ "application/vnd.openxmlformats-officedocument.presentationml.presentation", "pptx" },
		{ "application/vnd.openxmlformats-officedocument.presentationml.slide", "sldx" },
		{ "application/vnd.openxmlformats-officedocument.presentationml.slideshow", "ppsx" },
		{ "application/vnd.openxmlformats-officedocument.presentationml.template", "potx" },
		{ "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet", "xlsx" },
		{ "application/vnd.openxmlformats-officedocument.spreadsheetml.template", "xltx" },
		{ "application/vnd.openxmlformats-officedocument.wordprocessingml.document", "docx" },
		{ "application/vnd.openxmlformats-officedocument.wordprocessingml.template", "dotx" },
		{ "application/vnd.rn-realplayer", "rnx" },
		{ "application/vnd.wap.wmlc", "wmlc" },
		{ "application/vnd.wap.wmlscriptc", "wmlsc" },
		{ "application/vnd.xara", "xar" },
		{ "application/vocaltec-media-desc", "vmd" },
		{ "application/vocaltec-media-file", "vmf" },
		{ "application/vsix", "vsix" },
		{ "application/windows-library+xml", "library-ms" },
		{ "application/windows-search-connector+xml", "searchconnector-ms" },
		{ "application/winhlp", "hlp" },
		{ "application/x-7z-compressed", "7z" },
		{ "application/x-asap", "asp" },
		{ "application/x-atlasmate-plugin", "oom" },
		{ "application/x-authoware-bin", "aab" },
		{ "application/x-authoware-map", "aam" },
		{ "application/x-authoware-seg", "aas" },
		{ "application/x-autocad", "dwg" },
		{ "application/x-bcpio", "bcpio" },
		{ "application/x-bzip2", "bz2" },
		{ "application/x-cdlink", "vcd" },
		{ "application/x-chat", "chat" },
		{ "application/x-cmx", "cmx" },
		{ "application/x-cnc", "ccn" },
		{ "application/x-cocoa", "cco" },
		{ "application/x-compress", "z" },
		{ "application/x-cpio", "cpio" },
		{ "application/x-cprplayer", "pqf" },
		{ "application/x-csh", "csh" },
		{ "application/x-cult3d-object", "co" },
		{ "application/x-digitalloca", "lcr" },
		{ "application/x-director", "dxr" },
		{ "application/x-dreamcast-vms", "vms" },
		{ "application/x-dreamcast-vms-info", "vmi" },
		{ "application/x-dvi", "dvi" },
		{ "application/x-earthtime", "etc" },
		{ "application/x-envoy", "evy" },
		{ "application/x-expandedbook", "ebk" },
		{ "application/x-gca-compressed", "gca" },
		{ "application/x-gps", "gps" },
		{ "application/x-gtar", "gtar" },
		{ "application/x-gzip", "gz" },
		{ "application/x-hdf", "hdf" },
		{ "application/x-installshield", "wis" },
		{ "application/x-ipix", "ipx" },
		{ "application/x-ipscript", "ips" },
		{ "application/x-jam", "jam" },
		{ "application/x-java-jnlp-file", "jnlp" },
		{ "application/x-javascript", "js" },
		{ "application/x-jtx+xps", "jtx" },
		{ "application/x-kjx", "kjx" },
		{ "application/x-koan", "skd" },
		{ "application/x-latex", "latex" },
		{ "application/x-lzh", "lzh" },
		{ "application/x-maker", "fm" },
		{ "application/x-mapserver", "mps" },
		{ "application/x-mascot", "mct" },
		{ "application/x-mif", "mif" },
		{ "application/x-mocha", "mocha" },
		{ "application/x-mpeg", "amc" },
		{ "application/x-mrm", "mrm" },
		{ "application/x-ms-application", "application" },
		{ "application/x-ms-license", "slupkg-ms" },
		{ "application/x-ms-vsto", "vsto" },
		{ "application/x-ms-wmd", "wmd" },
		{ "application/x-ms-wmz", "wmz" },
		{ "application/x-ms-xbap", "xbap" },
		{ "application/x-msaccess", "mdb" },
		{ "application/x-mscardfile", "crd" },
		{ "application/x-msclip", "clp" },
		{ "application/x-msdownload", "exe" },
		{ "application/x-msmediaview", "m13" },
		{ "application/x-msmetafile", "wmf" },
		{ "application/x-msmoney", "mny" },
		{ "application/x-mspublisher", "pub" },
		{ "application/x-msschedule", "scd" },
		{ "application/x-msterminal", "trm" },
		{ "application/x-mswrite", "wri" },
		{ "application/x-net-install", "ins" },
		{ "application/x-netcdf", "cdf" },
		{ "application/x-netfpx", "npx" },
		{ "application/x-neva1", "nva" },
		{ "application/x-nif", "nif" },
		{ "application/x-ns-proxy-autoconfig", "proxy" },
		{ "application/x-pan", "pan" },
		{ "application/x-perl", "pm" },
		{ "application/x-pkcs12", "p12" },
		{ "application/x-pkcs7-certificates", "p7b" },
		{ "application/x-pkcs7-certreqresp", "p7r" },
		{ "application/x-prc", "prc" },
		{ "application/x-rar-compressed", "rar" },
		{ "application/x-richlink", "rlf" },
		{ "application/x-rogerwilco", "rwc" },
		{ "application/x-salsa", "slc" },
		{ "application/x-scream", "nmz" },
		{ "application/x-sh", "sh" },
		{ "application/x-shar", "shar" },
		{ "application/x-shockwave-flash", "swf" },
		{ "application/x-skt-lbs", "mmf" },
		{ "application/x-skype", "skype" },
		{ "application/x-sprite", "spr" },
		{ "application/x-spt", "spt" },
		{ "application/x-stuffit", "sea" },
		{ "application/x-supercard", "sca" },
		{ "application/x-sv4cpio", "sv4cpio" },
		{ "application/x-sv4crc", "sv4crc" },
		{ "application/x-tar", "tar" },
		{ "application/x-tcl", "tcl" },
		{ "application/x-tex", "tex" },
		{ "application/x-texinfo", "texinfo" },
		{ "application/x-timbuktu", "tbt" },
		{ "application/x-tkined", "tki" },
		{ "application/x-troff", "roff" },
		{ "application/x-troff-man", "man" },
		{ "application/x-troff-me", "me" },
		{ "application/x-troff-ms", "ms" },
		{ "application/x-ustar", "ustar" },
		{ "application/x-uuencode", "uue" },
		{ "application/x-wais-source", "src" },
		{ "application/x-wxl", "wxl" },
		{ "application/x-x509-ca-cert", "cer" },
		{ "application/x-xdma", "xdma" },
		{ "application/x-xpinstall", "xpi" },
		{ "application/x-yumekara", "mof" },
		{ "application/x-yz1", "yz1" },
		{ "application/x-zaurus-zac", "zac" },
		{ "application/xaml+xml", "xaml" },
		{ "application/xhtml+xml", "xhtml" },
		{ "application/xml", "xml" },
		{ "application/xml-dtd", "dtd" },
		{ "application/zip", "zip" },
		{ "audio/aiff", "aiff" },
		{ "audio/amr-wb", "awb" },
		{ "audio/basic", "au" },
		{ "audio/echospeech", "esl" },
		{ "audio/ma1", "ma1" },
		{ "audio/ma2", "ma2" },
		{ "audio/ma3", "ma3" },
		{ "audio/ma5", "ma5" },
		{ "audio/melody", "imy" },
		{ "audio/mid", "mid" },
		{ "audio/mp4", "m4a" },
		{ "audio/mpeg", "mp3" },
		{ "audio/nsnd", "nsnd" },
		{ "audio/pmd", "pmd" },
		{ "audio/tsplayer", "tsi" },
		{ "audio/vib", "vib" },
		{ "audio/vnd.dlna.adts", "adt" },
		{ "audio/vnd.qcelp", "qcp" },
		{ "audio/voxware", "vox" },
		{ "audio/wav", "wav" },
		{ "audio/x-alpha5", "als" },
		{ "audio/x-epac", "pae" },
		{ "audio/x-mio", "mio" },
		{ "audio/x-mod", "mdz" },
		{ "audio/x-mpegurl", "m3u" },
		{ "audio/x-ms-wax", "wax" },
		{ "audio/x-ms-wma", "wma" },
		{ "audio/x-pac", "pac" },
		{ "audio/x-pn-realaudio", "rm" },
		{ "audio/x-pn-realaudio-plugin", "rpm" },
		{ "audio/x-rmf", "rmf" },
		{ "audio/x-smd", "smd" },
		{ "audio/x-twinvq", "vqf" },
		{ "audio/x-twinvq-plugin", "vqe" },
		{ "chemical/x-csml", "csml" },
		{ "chemical/x-embl-dl-nucleotide", "embl" },
		{ "chemical/x-gaussian-input", "gau" },
		{ "chemical/x-mdl-molfile", "mol" },
		{ "chemical/x-mopac-input", "mop" },
		{ "chemical/x-pdb", "pdb" },
		{ "drawing/x-dwf", "dwf" },
		{ "i-world/i-vrml", "ivr" },
		{ "image/bmp", "bmp" },
		{ "image/gif", "gif" },
		{ "image/ief", "ief" },
		{ "image/ifs", "ifs" },
		{ "image/j2k", "j2k" },
		{ "image/jpeg", "jpeg" },
		{ "image/nbmp", "nbmp" },
		{ "image/png", "png" },
		{ "image/si6", "si6" },
		{ "image/sis", "sis" },
		{ "image/svg-xml", "svg" },
		{ "image/svh", "svh" },
		{ "image/tiff", "tiff" },
		{ "image/toy", "toy" },
		{ "image/vnd", "svf" },
		{ "image/vnd.lgtwap.sis", "si9" },
		{ "image/vnd.ms-photo", "wdp" },
		{ "image/vnd.nok-oplogo-color", "nokia-op-logo" },
		{ "image/vnd.rn-realflash", "rf" },
		{ "image/vnd.rn-realpix", "rp" },
		{ "image/vnd.stiwap.sis", "si7" },
		{ "image/vnd.wap.wbmp", "wbmp" },
		{ "image/wavelet", "wi" },
		{ "image/x-cals", "cal" },
		{ "image/x-cmu-raster", "ras" },
		{ "image/x-dcx", "dcx" },
		{ "image/x-eri", "eri" },
		{ "image/x-fpx", "fpx" },
		{ "image/x-freehand", "fhc" },
		{ "image/x-icon", "ico" },
		{ "image/x-pcx", "pcx" },
		{ "image/x-pda", "pda" },
		{ "image/x-pict", "pict" },
		{ "image/x-portable-anymap", "pnm" },
		{ "image/x-portable-bitmap", "pbm" },
		{ "image/x-portable-graymap", "pgm" },
		{ "image/x-portable-pixmap", "ppm" },
		{ "image/x-quicktime", "qtif" },
		{ "image/x-rgb", "rgb" },
		{ "image/x-up-wpng", "wpng" },
		{ "image/x-xbitmap", "xbm" },
		{ "image/x-xpixmap", "xpm" },
		{ "image/x-xwindowdump", "xwd" },
		{ "magnus-internal/cgi", "cgi" },
		{ "message/rfc822", "eml" },
		{ "model/vnd.dwfx+xps", "dwfx" },
		{ "model/vnd.easmx+xps", "easmx" },
		{ "model/vnd.edrwx+xps", "edrwx" },
		{ "model/vnd.eprtx+xps", "eprtx" },
		{ "text/css", "css" },
		{ "text/html", "html" },
		{ "text/plain", "txt" },
		{ "text/richtext", "rtx" },
		{ "text/scriptlet", "sct" },
		{ "text/tab-separated-values", "tsv" },
		{ "text/vnd.rn-realtext", "rt" },
		{ "text/vnd.rn-realtext3d", "r3t" },
		{ "text/vnd.sun.j2me.app-descriptor", "jad" },
		{ "text/vnd.wap.wml", "wml" },
		{ "text/vnd.wap.wmlscript", "wmlscript" },
		{ "text/x-component", "htc" },
		{ "text/x-hdml", "hdml" },
		{ "text/x-mrml", "mrl" },
		{ "text/x-ms-contact", "contact" },
		{ "text/x-ms-group", "group" },
		{ "text/x-ms-iqy", "iqy" },
		{ "text/x-ms-odc", "odc" },
		{ "text/x-ms-rqy", "rqy" },
		{ "text/x-setext", "etx" },
		{ "text/x-sgml", "sgml" },
		{ "text/x-speech", "talk" },
		{ "text/x-vcard", "vcf" },
		{ "text/x-vmel", "mel" },
		{ "text/xml", "xml" },
		{ "text/xul", "xul" },
		{ "video/3gpp", "3gp" },
		{ "video/3gpp2", "3gp2" },
		{ "video/avi", "avi" },
		{ "video/isivideo", "fvi" },
		{ "video/mp4", "mp4" },
		{ "video/mpeg", "mpeg" },
		{ "video/quicktime", "mov" },
		{ "video/vdo", "vdo" },
		{ "video/vivo", "vivo" },
		{ "video/vnd.dlna.mpeg-tts", "tts" },
		{ "video/vnd.rn-realvideo", "rv" },
		{ "video/wavelet", "wv" },
		{ "video/x-mng", "mng" },
		{ "video/x-ms-asf", "asf" },
		{ "video/x-ms-wm", "wm" },
		{ "video/x-ms-wmv", "wmv" },
		{ "video/x-ms-wmx", "wmx" },
		{ "video/x-ms-wvx", "wvx" },
		{ "video/x-pv-pvx", "pvx" },
		{ "video/x-sgi-movie", "movie" },
		{ "workbook/formulaone", "vts" },
		{ "x-conference/x-cooltalk", "ice" },
		{ "x-lml/x-evm", "evm" },
		{ "x-lml/x-gdb", "gdb" },
		{ "x-lml/x-gps", "rte" },
		{ "x-lml/x-lak", "lak" },
		{ "x-lml/x-lml", "lml" },
		{ "x-lml/x-lmlpack", "lmlpack" },
		{ "x-lml/x-ndb", "ndb" },
		{ "x-world/x-svr", "svr" },
		{ "x-world/x-vream", "vrw" },
		{ "x-world/x-vrml", "vrml" },
		{ "x-world/x-vrt", "vrt" },
		{ NULL, NULL }
	};

	inline bool operator < (const MimeType& l,const MimeType& r)
	{
		return strcasecmp(l.ext_name, r.ext_name) < 0;
	}
	inline bool operator < (const MimeExtType& l,const MimeExtType& r)
	{
		return strcasecmp(l.mime_type, r.mime_type) < 0;
	}

	// Map the file name extension to MIME type.
	const char* ext_to_mime(const char* ext_name)
	{
		std::size_t _mime_count=sizeof(_mime_type_table)/sizeof(*_mime_type_table)-1;
		MimeType tmp = {ext_name, 0};
		const MimeType* tp = std::lower_bound(_mime_type_table + 0,
			_mime_type_table + _mime_count,
			tmp, std::less<MimeType>());
		if (tp != _mime_type_table + _mime_count && strcasecmp(tp->ext_name, ext_name) == 0)
			return tp->mime_type;
		else
			return NULL;
	}

	// Map the file name extension to MIME type.
	const char* mime_to_ext(const char* mime)
	{
		std::size_t _mime_ext_count=sizeof(_mime_ext_table)/sizeof(*_mime_ext_table)-1;

		MimeExtType tmp = {mime, 0};
		const MimeExtType* tp = std::lower_bound(_mime_ext_table + 0,
			_mime_ext_table + _mime_ext_count,
			tmp, std::less<MimeExtType>());
		if (tp != _mime_ext_table + _mime_ext_count && strcasecmp(tp->mime_type, mime) == 0)
			return tp->ext_name;
		else
			return NULL;
	}

} // namespace mime_types
} // namespace http
} // namespace p2engine
