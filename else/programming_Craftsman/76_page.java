public class Main
{
    public static void main(String[] args)
    {
        int[] n = {5, 4, 3, 2, 1};
        for (int i = 0; i < 5; i++)
            System.out.printf("%d",n[5%(4-i)]);
    }
}