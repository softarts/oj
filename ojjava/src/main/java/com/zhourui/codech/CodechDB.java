package com.zhourui.codech;

import org.reflections.Reflections;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Set;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.ThreadPoolExecutor;

public class CodechDB {
    private static CodechDB instance ;

    private ThreadPoolExecutor executor =
            (ThreadPoolExecutor) Executors.newFixedThreadPool(5);

    private CountDownLatch cdl;

    private CodechDB(){

    }
    public static CodechDB getInstance(){
        if (instance==null)
            instance = new CodechDB();
        return instance;
    }

    public void register(BaseSolution e) {
        baseSolutionArrayList.add(e);

    }
    private ArrayList<BaseSolution> baseSolutionArrayList=new ArrayList();

    private void scan() {
        Reflections reflections = new Reflections("com.zhourui.leetcode");
        Set<Class<? extends BaseSolution>> allClasses = reflections.getSubTypesOf(BaseSolution.class);


//        for (Class<? extends BaseSolution> bs:allClasses) {
//            try {
//                bs.getDeclaredConstructors()[0].newInstance();
//            } catch (Exception e) {
//                System.out.println(e.toString());
//            }
//        }

//        allClasses.forEach(
//                x-> {
//
//                    executor.submit(()->{
//                        try {
//                            x.getDeclaredConstructors()[0].newInstance();
//                        } catch (Exception e) {
//                            System.out.println(e.toString());
//                        }
//                    });
//                }
//        );
        allClasses.forEach(
            x-> {
                try {
                    Method methodToFind = null;
                    //x.getMethod("test")
                    try {
                        methodToFind = x.getMethod("test", (Class<?>[]) null);
                    } catch (NoSuchMethodException | SecurityException e) {
                        // Your exception handling goes here
                    }

                    if(methodToFind == null) {
                        // Method not found.
                    } else {
                        // Method found. You can invoke the method like
                        if (isMethodOverrriden(methodToFind)) {
                            x.getDeclaredConstructors()[0].newInstance();
                        }

                    }
                } catch (Exception e) {
                    System.out.println(e.toString());
                }
            }
        );
    }


    public static boolean isMethodOverrriden(Method myMethod) {
        Class<?> declaringClass = myMethod.getDeclaringClass();
        if (declaringClass.equals(Object.class)) {
            return false;
        }
        try {
            declaringClass.getSuperclass().getMethod(myMethod.getName(), myMethod.getParameterTypes());
            return true;
        } catch (NoSuchMethodException e) {
            return false;
        }
    }


    void run(){
        scan();
        System.out.println("---- SCAN done --------------------");
        //Arrays.sort(baseSolutionArrayList);
        baseSolutionArrayList.sort(
                (a,b) -> {
                    return a.getClass().getSimpleName().compareTo(b.getClass().getSimpleName());
                }
        );
        for (int i=0;i<baseSolutionArrayList.size();i++) {
            System.out.println(String.format("#%d %s", i, baseSolutionArrayList.get(i).getClass().getSimpleName()));
        }

        // console input
        System.out.print( "Please enter a question number : " );
        BufferedReader reader =
                new BufferedReader(new InputStreamReader(System.in));
        try {
            String idxstr = reader.readLine();
            int idx = Integer.parseInt(idxstr);
            //System.out.println(baseSolutionArrayList.get(idx).test()==true);
            Future<Boolean> fut = executor.submit(()->{
                return baseSolutionArrayList.get(idx).test();
            });
            System.out.println(String.format("#%s result = %s",idxstr, fut.get()));
        } catch (Exception e) {
            System.out.println(e.toString());
        }
    }


}
