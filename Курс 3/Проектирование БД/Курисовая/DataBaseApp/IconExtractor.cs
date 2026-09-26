using System;
using System.Drawing;
using System.Runtime.InteropServices;

namespace DataBaseApp
{
    public static class IconExtractor
    {
        [DllImport("shell32.dll", CharSet = CharSet.Auto)]
        private static extern uint ExtractIconEx(string szFileName, int nIconIndex, IntPtr[] phiconLarge, IntPtr[] phiconSmall, uint nIcons);

        public static Icon Extract(string file, int number, bool largeIcon = true)
        {
            IntPtr[] large = new IntPtr[1];
            IntPtr[] small = new IntPtr[1];

            ExtractIconEx(file, number, large, small, 1);

            IntPtr handle = largeIcon ? large[0] : small[0];

            if (handle == IntPtr.Zero) return null;

            return Icon.FromHandle(handle);
        }
    }
}
