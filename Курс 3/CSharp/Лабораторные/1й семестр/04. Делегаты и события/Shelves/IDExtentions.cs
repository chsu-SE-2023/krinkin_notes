using Goods;

namespace Shelves;

internal static class IDExtentions
{
    public static void OnIDChanged<T>(this T product, IShelve<T> shelve) where T : class, IProduct
    {
        var pos = shelve.Search(product.ID);
        if (pos != -1) product?.OnIDChanged(shelve, pos);
    }

    public static void OnIDChanged<T>(this T product, IShelve<T> shelve, int pos) where T: class, IProduct
    {
        product.QRData.Text = $"{product!.ID} {shelve.ID} {pos}";
    }
}
