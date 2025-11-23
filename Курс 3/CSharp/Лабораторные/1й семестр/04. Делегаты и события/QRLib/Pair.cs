public record Pair(int X, int Y)
{
    public static implicit operator Pair((int x, int y) pos) => new(pos.x, pos.y);
} 
 
