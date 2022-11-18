public class Main {

    public static void main(String[] args) {
        System.loadLibrary("HelloJNI");
        HelloJNI m = new HelloJNI();
        try {
            String str = m.test("422");
            System.out.println("HelloJNI test " + str);
        } catch (Throwable e) {
            e.printStackTrace();
        }
        try {
            int str = m.test(123);
            System.out.println("HelloJNI test " + str);
        } catch (Throwable e) {
            e.printStackTrace();
        }
        try {
            System.out.println("HelloJNI ctime ");
            m.ctime();
        } catch (Throwable e) {
            e.printStackTrace();
        }
        try {
            System.out.println("HelloJNI time ");
            m.time();
        } catch (Throwable e) {
            e.printStackTrace();
        }
    }
}