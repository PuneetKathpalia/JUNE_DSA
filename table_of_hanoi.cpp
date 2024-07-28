// Link : https://www.geeksforgeeks.org/problems/tower-of-hanoi/1

import java.io.*;
import java.util.*;
class Recursion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();//total testcases
        while (T-- > 0) {
…        // the help of 'from'.
        moves += toh(N - 1, aux, to, from);
        return moves;
    }
}