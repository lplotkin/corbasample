/**
 * Simple java CORBA client
 */
import org.omg.CORBA.*;

public class client {
    public static void main(String [] args) {
        if(args.length < 2) {
            System.err.println("usage: helloClient IOReference stringToReverse");
            System.exit(2);
        }
        try {
            ORB orb = ORB.init(args, null);

            org.omg.CORBA.Object obj = orb.string_to_object(args[0]);

            hello instance = helloHelper.narrow(obj);

            if(null == instance) {
                System.err.println("Can't get instance.");
                System.exit(1);
            }
            System.out.println("Remote said: " + instance.sayHello(args[1]));
        } catch ( Throwable t ) {
            System.err.println("Caught an unknown exception.");
        }
    }
}
