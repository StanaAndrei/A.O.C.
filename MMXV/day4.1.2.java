import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class Main {
    final static short PUZZLE_PART = 2;
    final static String TARGET = (PUZZLE_PART == 1) ? "00000" : "000000";

    private static int findAdventCoin(final String secretKey) throws NoSuchAlgorithmException {
        int nr = 1;
        var md = MessageDigest.getInstance("MD5");
        while (true) {
            final String input = secretKey + nr;
            byte[] digest = md.digest(input.getBytes());
            final String hash = toHexStr(digest);
            if (hash.startsWith(TARGET)) {
                return nr;
            }
            nr++;
        }
    }

    private static String byteToHex(byte b) {
        var hexDigs = new char[2];
        hexDigs[0] = Character.forDigit((b >> 4) & 0xF, 16);
        hexDigs[1] = Character.forDigit(b & 0xF, 16);
        return new String(hexDigs);
    }

    private static String toHexStr(byte[] bytes) {
        var sb = new StringBuilder();
        for (int i = 0; i < bytes.length; i++) {
            sb.append(byteToHex(bytes[i]));
        }
        return sb.toString();
    }

    public static void main(String[] args) throws NoSuchAlgorithmException {
        final String secretKey = "iwrupvqb";
        final int ans = findAdventCoin(secretKey);
        System.out.println(ans);
    }
}
