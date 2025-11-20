using Goods;
using System.Xml.Linq;

namespace Shelves;

internal static class IDExtentions
{
    public static void OnIDChanged<T>(this T product, Shelve<T> shelve) where T : class, IProduct
    {
        product?.OnIDChanged(shelve, shelve.Search(product.ID).ID);
    }

    public static void OnIDChanged<T>(this T product, Shelve<T> shelve, int pos) where T: class, IProduct
    {
        product.QRData.Text = $"{product!.ID} {shelve.ID} {pos}";
    }
}
