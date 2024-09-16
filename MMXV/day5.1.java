import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.List;
import java.util.function.Predicate;
import java.util.stream.IntStream;

class NiceStrChecker {
    private NiceStrChecker() {}

    private final static String VOWELS = "aeiou";
    private final static Predicate<String> has3Vowels = s -> s.chars()
            .filter(c -> VOWELS.indexOf(c) != -1)
            .count() >= 3;

    private static final Predicate<String> hasX2Letter = s -> IntStream.range(1, s.length())
            .anyMatch(i -> s.charAt(i) == s.charAt(i - 1));

    private final static String[] BANNED = new String[]{"ab", "cd", "pq", "xy"};
    private final static Predicate<String> noBannedSubstr = s -> List.of(BANNED).stream()
            .noneMatch(s::contains);

    public static boolean isNice(final String s) {
        return has3Vowels.and(hasX2Letter)
                .and(noBannedSubstr).test(s);
    }
}

public class Main {
    public static void main(String[] args) {
        try {
            final long ans = Files.lines(Path.of("data.txt"))
                    .filter(NiceStrChecker::isNice)
                    .count();
            System.out.println(ans);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
