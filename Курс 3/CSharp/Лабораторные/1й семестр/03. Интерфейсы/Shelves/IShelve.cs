using Goods;

namespace Shelves
{
    public interface IShelve<T> where T : class, IProduct
    {
        T? this[int index] { get; set; }

        int ID { get; set; }

        void Add(T product);
        void Add(T product, int index);
        void OrderByID();
        void OrderByName();
        void Remove(int index);
        void Remove(T product);
        T? Replace(T product, int index);
        T? Search(int id);
        T? Search(string name);
        void Swap(int index, int new_index);
    }
}