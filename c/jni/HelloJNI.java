import java.time.LocalDateTime;

public class HelloJNI {

    public native String test(String str);

    public native int test(int inti);

    public native void ctime();

    public void time() {
        System.out.println(LocalDateTime.now().toString());
    }

}