import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ObserverPattern {
/******************************************************
 A bunch of Observers are watching the Subject.

 When the subject do something, his observer would all
 begin to do something immediately.
 *******************************************************/
    public static void main(String[] args) {
        Subject subject = new Subject();

        // Note that those observers have no name!
        // This is probably a Java thing.
        // You dont have to care about their memory somehow :)
        new HexObserver(subject);
        new OctObserver(subject);
        new BinObserver(subject);
        Scanner scan = new Scanner(System.in);

        do {
            System.out.println("\nEnter a number: ");
            subject.setState(scan.nextInt());

        } while (subject.getState() != 0);
    }
}

/* Expected output
Enter a number:
    13
    Hex:d
    Octal:15
    Binary:1101*/


abstract class Observer {
    protected Subject subject;

    public abstract void update();
}

class Subject {
    private final List<Observer> observers = new ArrayList<>();
    private int state;

    public void add(Observer ob) {
        observers.add(ob);
    }

    public int getState() {
        return state;
    }

    public void setState(int value) {
        this.state = value;
        // Note that this execute() is private;
        // This means that whenever the user set a state,
        // something would happened.
        // In this case, it means the observers would got some updates.
        execute();
    }

    private void execute() {
        for (Observer ob : observers) {
            ob.update();
        }
    }

}

/* Lets define some observers */

class HexObserver extends Observer {
    public HexObserver(Subject subject) {
        this.subject = subject;
        this.subject.add(this);
    }

    public void update() {
        System.out.println("Hex:" + Integer.toHexString(subject.getState()));
    }
}

class OctObserver extends Observer {
    public OctObserver(Subject subject) {
        this.subject = subject;
        this.subject.add(this);
    }

    public void update() {
        System.out.println("Octal:" + Integer.toOctalString(subject.getState()));
    }
}

class BinObserver extends Observer {
    public BinObserver(Subject subject) {
        this.subject = subject;
        this.subject.add(this);
    }

    public void update() {
        System.out.println("Binary:" + Integer.toBinaryString(subject.getState()));
    }
}
