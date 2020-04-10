package com.zhourui.codech;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class CodechDB {
    private static CodechDB instance ;
    private CodechDB(){}

    public static CodechDB getInstance(){
        if (instance==null)
            instance = new CodechDB();
        return instance;
    }

    public void register(BaseSolution e) {
        baseSolutionArrayList.add(e);
    }
    private ArrayList<BaseSolution> baseSolutionArrayList=new ArrayList();

    void run(){
        for (int i=0;i<baseSolutionArrayList.size();i++) {
            System.out.println(String.format("#%d %s", i, baseSolutionArrayList.get(i).name()));
        }

        // console input
        System.out.print( "Please enter a question number : " );
        BufferedReader reader =
                new BufferedReader(new InputStreamReader(System.in));
        try {
            String idxstr = reader.readLine();
            int idx = Integer.parseInt(idxstr);
            System.out.println(baseSolutionArrayList.get(idx).test()==true);
        } catch (IOException e) {
            System.out.println(e.toString());
        }
    }


}
