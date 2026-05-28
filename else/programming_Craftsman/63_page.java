public class Main {
    public static void main(String[]args)
    {
        int result, a = 100, b = 200, c = 300;
        result = a < b ? b++ : --c;
        System.out.printf("%d, %d, %d\n", result, b, c);
    }
}

public class Main {
    public static void main(String[] args)
    {
        int j = 024;
        int k = 24;
        int l = 0x24;
        int hap = j + k + l;
        System.out.printf("%d, %d, %d, %d\n", j, k, l, hap);
    }
}