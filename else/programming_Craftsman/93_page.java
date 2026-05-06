interface Op
{
    int calc1(int a, int b);
    default void calc2()
    {
        System.out.print("Good");
    }
}
class Add implements Op{
    public int calc1(int a, int b)
    {
        return a+b;
    }
    public void calc2()
    {
        System.out.print("Fine");
    }
}

public class Main
{
    public static void main(String[] args)
    {
        int a = 10, b = 5;
        Op add = new Add();
        System.out.println(add.calc1(a, b));
        add.calc2();
    }
}