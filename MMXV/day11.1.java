import java.util.Optional;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.Predicate;
import java.util.stream.IntStream;
import java.util.stream.Stream;

class AlphaNr {
    private String buffer;

    public AlphaNr(final String buffer) {
        this.buffer = buffer;
    }

    public void increment() {
        this.buffer = incrementHelper(buffer, buffer.length() - 1);
    }

    public AlphaNr incrementAndGet() {
        this.increment();
        return this;
    }

    private static String incrementHelper(String current, int index) {
        // Base case: if index is out of bounds, prepend 'a'
        if (index < 0) {
            return 'a' + current;
        }

        char ch = current.charAt(index);
        if (ch == 'z') {
            // If it's 'z', replace with 'a' and recursively move to the next character
            return incrementHelper(current.substring(0, index) + 'a' + current.substring(index + 1), index - 1);
        }
        // Increment the character and return the new string
        return current.substring(0, index) + (char) (ch + 1) + current.substring(index + 1);
    }

    public String getBuffer() {
        return buffer;
    }

    @Override
    public String toString() {
        return "AlphaNr{" +
                "buffer='" + buffer + '\'' +
                '}';
    }
}

class PasswordValidator {
    private PasswordValidator() {}

    private static Predicate<String> containsIncr = s -> IntStream.range(0, s.length() - 2)
            .anyMatch(i -> s.charAt(i) + 1 == s.charAt(i + 1) && s.charAt(i) + 2 == s.charAt(i + 2));

    private static final String BANNED = "iol";
    private static Predicate<String> hasBanned = s -> s.chars()
            .anyMatch(c -> BANNED.contains(Character.toString(c)));

    private static final int TARGET = 2;
    private static Predicate<String> hasMinTargetNonOverlappingPairs = s -> {
      var pairCnt = new AtomicInteger();
      var skipNxt = new AtomicBoolean();

      IntStream.range(0, s.length() - 1)
              .forEach(i -> {
                  if (s.charAt(i) == s.charAt(i + 1) && !skipNxt.get()) {
                      pairCnt.incrementAndGet();
                      skipNxt.set(true);
                  } else {
                      skipNxt.set(false);
                  }
              });

      return pairCnt.get() >= TARGET;
    };

    public static boolean isValid(final String password) {
        return containsIncr.and(hasBanned.negate())
                .and(hasMinTargetNonOverlappingPairs).test(password);
    }
}

public class Main {
    public static void main(String[] args) {
        final String input = "hxbxxyzz";
        Optional<AlphaNr> ans = Stream.iterate(new AlphaNr(input), anr -> anr.incrementAndGet())
                .filter(anr -> PasswordValidator.isValid(anr.getBuffer())).findFirst();
        assert ans.isPresent();
        System.out.println(ans.get());//*/
    }
}
