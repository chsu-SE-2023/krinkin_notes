namespace Goods;

public sealed class IDChangeEvent(int oldID, int newID) : EventArgs
{
    public int OldID { get; } = oldID;
    public int NewID { get; } = newID;
}