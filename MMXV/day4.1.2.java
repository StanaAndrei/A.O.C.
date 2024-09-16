import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Optional;
import java.util.stream.IntStream;

public class Main {
    final static short PUZZLE_PART = 1;
    final static String TARGET = (PUZZLE_PART == 1) ? "00000" : "000000";

    private static Optional<Integer> findAdventCoin(final String secretKey) throws NoSuchAlgorithmException {
        var md = MessageDigest.getInstance("MD5");
        return IntStream.iterate(1, nr -> nr + 1)
                .mapToObj(nr -> new Object[] { nr, md.digest((secretKey + nr).getBytes()) })
                .filter(data -> toHexStr((byte[]) data[1]).startsWith(TARGET))
                .map(data -> (Integer) data[0])
                .findFirst();
    }

    private static String byteToHex(byte b) {
        var hexDigs = new char[2];
        hexDigs[0] = Character.forDigit((b >> 4) & 0xF, 16);
        hexDigs[1] = Character.forDigit(b & 0xF, 16);
        return new String(hexDigs);
    }

    private static String toHexStr(byte[] bytes) {
        return IntStream.range(0, bytes.length)
                .mapToObj(i -> byteToHex(bytes[i]))
                .reduce(new StringBuilder(), StringBuilder::append, StringBuilder::append)
                .toString();
    }

    public static void main(String[] args) throws NoSuchAlgorithmException {
        final String secretKey = "iwrupvqb";
        findAdventCoin(secretKey).ifPresent(System.out::println);
    }
}
