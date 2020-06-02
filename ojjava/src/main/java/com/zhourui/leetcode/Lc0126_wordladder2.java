package com.zhourui.leetcode;

import com.zhourui.codech.BaseSolution;

import java.util.*;
import static java.lang.Integer.*;
//Input:
//beginWord = "hit",
//endWord = "cog",
//wordList = ["hot","dot","dog","lot","log","cog"]
//
//Output:
//[
//["hit","hot","dot","dog","cog"],
//["hit","hot","lot","log","cog"]
//]
//找出所有的最短路径
// 此题难点在于不能删除已找到的路径，因为其他路径可能要用
public class Lc0126_wordladder2 extends BaseSolution {
    class Pair {
        public LinkedHashSet<String> links;
        public String word;
        Pair(LinkedHashSet<String> _links, String _word) {
            word = _word;
            links = _links;
        }
    };

    // 这个做法仍然很慢,每一个path都带了一个hashset来排除重复字符串，
    // 这里需要优化,比如 level 4中都出现了abcd,那么level5之后就不应该再出现，否则就是重复劳动
    class Solution0 {
        public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
            List<List<String>> ret = new LinkedList<>();
            Pair root = new Pair(new LinkedHashSet<String>(Arrays.asList(beginWord)), beginWord);
            LinkedList<Pair> todo = new LinkedList(Arrays.asList(root));
            HashSet<String> words= new HashSet<>(wordList);
            if (!wordList.contains(endWord)) {
                return ret;
            }
            PriorityQueue<LinkedHashSet<String>> pq = new PriorityQueue(new Comparator<LinkedHashSet<String>>() {
                @Override
                public int compare(LinkedHashSet<String> o1, LinkedHashSet<String> o2) {
                    return o1.size() - o2.size();
                }
            });


//
            int shortpath = Integer.MAX_VALUE;
            while (!todo.isEmpty()) {
                var sz = todo.size();
                for (int i=0;i<sz;i++) {
                    var pr = todo.poll();
                    for (var el:pr.links) {
                        System.out.printf("%s ",el);
                    }
                    System.out.println(" ");


                    if (pr.word.equals(endWord)) {
                        shortpath = min(shortpath,pr.links.size());
                        pq.offer(pr.links);
                    } else if (pr.links.size() < shortpath){
                        dfs(pr,words,todo,endWord);
                    }
                }
            }

            int shortest = !pq.isEmpty()?pq.peek().size():0;
            System.out.println("===========");
            while (!pq.isEmpty() && pq.peek().size()==shortest) {
                LinkedList<String> el = new LinkedList<>(pq.poll());
                ret.add(el);
                for (var item:el) {
                    System.out.printf("%s ",item);
                }
                System.out.println(" ");
            }
            return ret;
        }

        void dfs(Pair pr, HashSet<String> words, LinkedList<Pair> todo, String endWord) {
            LinkedHashSet<String> path = pr.links;
            String word = pr.word;

            char buf[] = word.toCharArray();
            for (int i=0;i<buf.length;i++) {
                char old = buf[i];
                for (char j='a';j<='z';j++) {
                    if (j!=buf[i]) {
                        buf[i] = j;
                        String nextWord = String.valueOf(buf);
                        if (words.contains(nextWord) && !path.contains(nextWord)) {
                            LinkedHashSet<String> newPath = new LinkedHashSet<>();
                            newPath.addAll(path);
                            newPath.add(nextWord);
                            Pair npr = new Pair(newPath, nextWord);
                            todo.offer(npr);
                        }
                        buf[i]=old;
                    }
                }
            }
        }
    }

    // 这个做法仍然很慢,每一个path都带了一个hashset来排除重复字符串，
    // 这里需要优化,比如 level 4中都出现了abcd,那么level5之后就不应该再出现，否则就是重复劳动
    class Solution {
        public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
            List<List<String>> ret = new LinkedList<>();
            HashSet<String> dict = new HashSet<String>(wordList);
            LinkedList<String> path = new LinkedList<String>(Arrays.asList(beginWord));
            LinkedList<LinkedList<String>> todo = new LinkedList(Arrays.asList(path));
            HashSet<String> levelDict = new HashSet<String>();
            int curLevel = 1;
            int maxLevel = MAX_VALUE;
            while (!todo.isEmpty()) {
                LinkedList<String> p = todo.poll();
                if (p.size() > curLevel) {
                    for (String w:levelDict) {
                        dict.remove(w);
                    }
                    levelDict.clear();
                    curLevel = p.size();
                    if (curLevel > maxLevel) break;
                }

                String lastW = p.getLast();
                char buf[] = lastW.toCharArray();
                for (int i=0;i<buf.length;i++) {
                    char old = buf[i];
                    for (char j='a';j<='z';j++) {
                        if (j!=buf[i]) {
                            buf[i] = j;
                            String nextWord = String.valueOf(buf);
                            if (dict.contains(nextWord)) {
                                levelDict.add(nextWord);

                                LinkedList<String> newPath = new LinkedList();
                                newPath.addAll(p);
                                newPath.add(nextWord);
                                if (nextWord.equals(endWord)) {
                                    ret.add(newPath);
                                    maxLevel = curLevel;
                                    break;
                                } else {
                                    todo.offer(newPath);
                                }
                            }
                        }
                        buf[i]=old;
                    }
                }
            }
            return ret;
        }
    }

            @Override
    public boolean test() {
        /*
        "qa"
"sq"
["si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"]
         */

        var slu = new Solution();
        //slu.findLadders("qa","sq",Arrays.asList("si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"));
        //slu.findLadders("cet","ism",Arrays.asList("kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"));


//        var slu = new Solution();
        slu.findLadders("hit","cog",Arrays.asList("hot","dot","dog","lot","log","cog"));
        return true;
    }
}
