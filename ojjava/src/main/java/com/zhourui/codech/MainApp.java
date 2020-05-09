package com.zhourui.codech;


//import com.zhourui.leetcode.Lc0001_twosum;
//import org.reflections.Reflections;
//
//import java.lang.reflect.Constructor;
//import java.util.Set;
//import java.lang.reflect.Constructor;
//import java.util.concurrent.Executors;
//import java.util.concurrent.ThreadPoolExecutor;

public class MainApp {
    //private static Object Constructor;

    public static void main (String[] args)
    {
        System.out.println("Hello World! This is JAVA OJ");
//        Reflections reflections = new Reflections("com.zhourui.leetcode");
//        Set<Class<? extends BaseSolution>> allClasses = reflections.getSubTypesOf(BaseSolution.class);
//
//
////        for (Class<? extends BaseSolution> bs:allClasses) {
////            try {
////                bs.getDeclaredConstructors()[0].newInstance();
////            } catch (Exception e) {
////                System.out.println(e.toString());
////            }
////        }
//
//        allClasses.forEach(
//            x-> {
//                try {
//                    x.getDeclaredConstructors()[0].newInstance();
//                } catch (Exception e) {
//                    System.out.println(e.toString());
//                }
//            }
//        );
        CodechDB.getInstance().run();

//        allClasses.forEach(
//                x->
//                        x.getDeclaredConstructors().
//
//        );
//        subclasses.toList.map { x =>
//        try {
//            println(x.getDeclaredConstructors()(0))
//
//
//        } catch {
//            case _:Throwable => println("something wrong")
//        }
//        x.getDeclaredConstructors()(0).newInstance().asInstanceOf[BaseExtension]
//    }

        //CodechDB.getInstance().run();
    }
}
