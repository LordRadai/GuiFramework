#include "GUIMemorySizeFormatter.h"
#include <Call.h>

namespace GuiFramework
{
	namespace GUIMemorySizeFormatter
	{
		typedef void(__fastcall* Format_t)(dl_int*, DLTX::DLString&, dl_uint64);

		void GUIMemorySizeFormatter::Format(dl_int* pFmt, DLTX::DLString& str, dl_size size)
		{
			CALL(Format_t, 0xc54910, pFmt, str, size);
		}
	}
}