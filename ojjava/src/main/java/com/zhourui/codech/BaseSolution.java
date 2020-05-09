package com.zhourui.codech;

import static java.lang.Math.min;

public abstract class BaseSolution {
    public BaseSolution() {
        System.out.println(String.format("%s %s","register", name()));
        //this.name = n;
        CodechDB.getInstance().register(this);

    }
    //基类的protected成员是包内可见的，并且对子类可见；
    //若子类与基类不在同一包中，那么在子类中，子类实例可以访问其从基类继承而来的protected方法，而不能访问基类实例的protected方法。

    //public String name;

    public boolean test() {return true;}
    public String name() {
        //return "default name";
        return this.getClass().getSimpleName();
    }

}
