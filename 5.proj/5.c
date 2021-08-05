/*
 * ============================================================================
 *
 *       Filename:  5.c
 *
 *    Description:
 * https://leetcode-cn.com/problems/longest-palindromic-substring/
 *
 *        Version:  1.0
 *        Created:  08/04/21 16:58:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  "Peng Li"<aqnote@aqnote.com>
 *   Organization:
 *
 * ============================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LENGTH 1001

void strrev(char *s) {
    if (NULL == s)
        return;

    char *pBegin = s;
    char *pEnd = s + strlen(s) - 1;

    char pTemp;

    while (pBegin < pEnd) {
        pTemp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = pTemp;

        ++pBegin, --pEnd;
    }
}

char isPalindrome(char *s) {

    char tmp[LENGTH];
    int result;
    int len;
    strcpy(tmp, s);

    len = strlen(s);
    tmp[len] = '\0';

    strrev(tmp);
    result = strncmp(s, tmp, len);

    return result;
}

char maxPalindrome[LENGTH];
char *longestPalindrome(char *s) {
    int max, i, j, len;
    char substr[LENGTH];

    max = 0;
    maxPalindrome[0] = '\0';

    len = strlen(s);
    for (i = 0; i < len; i++) {
        for (j = 0; j < len - i; j++) {
            // 判断首尾不同，确定不是回文，重新找【KeyPoint】
            if (s[i] != s[len - j - 1])
                continue;
            // 比剩下的子串长，说明目前这个是最大了，重新下一轮
            if (max > len - i - j)
                continue;
            // 获取子串
            strncpy(substr, &s[i], len - i - j);
            substr[len - i - j] = '\0';
            // 判断是否子串：如果是，进入处理
            if (isPalindrome(substr) == 0) {
                int size = len - i - j;
                // 是当前最大子串，进入处理
                if (size > max) {
                    max = size; // 设置最大回文子串长度
                    strcpy(maxPalindrome, substr); // 设置最大回文子串内容
                }
            }
        }
    }
    return maxPalindrome;
}

int main(int argc, char *argv[]) {
    // "caba"  "aba"
    printf("%s\n", longestPalindrome("caba"));
    printf("%s\n", longestPalindrome("babad"));
    printf("%s\n", longestPalindrome("cbbd"));
    printf("%s\n", longestPalindrome("a"));
    printf("%s\n", longestPalindrome("ac"));
    printf(
        "%s\n",
        longestPalindrome(
            "esbtzjaaijqkgmtaajpsdfiqtvxsgfvijpxrvxgfumsuprzlyvhclgkhccmcnquuki"
            "vlpnjlfteljvykbddtrpmxzcrdqinsnlsteonhcegtkoszzonkwjevlasgjlcquzuh"
            "dmmkhfniozhuphcfkeobturbuoefhmtgcvhlsezvkpgfebbdbhiuwdcftenihseory"
            "kdguoqotqyscwymtjejpdzqepjkadtftzwebxwyuqwyeegwxhroaaymusddwnjkvsv"
            "rwwsmolmidoybsotaqufhepinkkxicvzrgbgsarmizugbvtzfxghkhthzpuetufqvi"
            "gmyhmlsgfaaqmmlblxbqxpluhaawqkdluwfirfngbhdkjjyfsxglsnakskcbsyafqp"
            "wmwmoxjwlhjduayqyzmpkmrjhbqyhongfdxmuwaqgjkcpatgbrqdllbzodnrifvhcf"
            "vgbixbwywanivsdjnbrgskyifgvksadvgzzzuogzcukskjxbohofdimkmyqypyuexy"
            "pwnjlrfpbtkqyngvxjcwvngmilgwbpcsseoywetatfjijsbcekaixvqreelnlmdonk"
            "nmxerjjhvmqiztsgjkijjtcyetuygqgsikxctvpxrqtuhxreidhwcklkkjayvqdzqq"
            "apgdqaapefzjfngdvjsiiivnkfimqkkucltgavwlakcfyhnpgmqxgfyjziliyqhugp"
            "hhjtlllgtlcsibfdktzhcfuallqlonbsgyyvvyarvaxmchtyrtkgekkmhejwvsuumh"
            "cfcyncgeqtltfmhtlsfswaqpmwpjwgvksvazhwyrzwhyjjdbphhjcmurdcgtbvpkhb"
            "kpirhysrpcrntetacyfvgjivhaxgpqhbjahruuejdmaghoaquhiafjqaionbrjbjks"
            "xaezosxqmncejjptcksnoq"));
    printf(
        "%s\n",
        longestPalindrome(
            "flsuqzhtcahnyickkgtfnlyzwjuiwqiexthpzvcweqzeqpmqwkydhsfipcdrsjkefe"
            "hhesubkirhalgnevjugfohwnlhbjfewiunlgmomxkafuuokesvfmcnvseixkkzekui"
            "nmcbmttzgsqeqbrtlwyqgiquyylaswlgfflrezaxtjobltcnpjsaslyviviosxorjs"
            "fncqirsjpkgajkfpoxxmvsyynbbovieoothpjgncfwcvpkvjcmrcuoronrfjcppbis"
            "qbzkgpnycqljpjlgeciaqrnqyxzedzkqpqsszovkgtcgxqgkflpmrikksaupukdvkz"
            "bltvefitdegnlmzeirotrfeaueqpzppnsjpspgomyezrlxsqlfcjrkglyvzvqakhtv"
            "fmeootbtbwfhqucbnuwznigoyatvkocqmbtqghybwrhmyvvuchjpvjckiryvjfxabe"
            "zchynfxnpqaeampvaapgmvoylyutymdhvhqfmrlmzkhuhupizqiujpwzarnszrexpv"
            "gdmtoxvjygjpmiadzdcxtggwamkbwrkeplesupagievwsaaletcuxtpsxmbmeztcyl"
            "sjxvhzrqizdmgjfyftpzpgxateopwvynljzffszkzzqgofdlwyknqfruhdkvmvrrjp"
            "ijcjomnrjjubfccaypkpfokohvkqndptciqqiscvmpozlyyrwobeuazsawtimnawqu"
            "ogrohcrnmexiwvjxgwhmtpykqlcfacuadyhaotmmxevqwarppknoxthsmrrknu"));
    printf("%s\n",
           longestPalindrome(
               "dqlvtrcystnncxjffjrkiiqgtcunbwntqrpqkjepzbxzodeckrbrwzjjuptloyp"
               "mjgbwioqtjzjjgqpaemgvxkapjgbfhhwltvtqgkozuzvlwetftjeocjqrdwlhdw"
               "tgzdhwvmuhvmdpkxnzrrizjntxbbpzwtjryecgfajolalwdzxqtknvvvaxuhanz"
               "owlbwjraigvrflcqoormbeexekmqpmuuobseumctsiwhvdohywjaylixqgqookg"
               "neokebtmoyaspnzbwqzffyocvcylcjobnzbmhsdprzrgdlyzuutyuwygzeldfew"
               "icjnukguisceeopckkoviayrcqanzsryhwqhxjxcpiejojztrxad"));

    return 0;
}
