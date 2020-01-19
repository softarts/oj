package com.zhourui.codech

// https://github.com/zmoazeni/reflections-example/tree/master/reflections-base/src/main/scala/org/reflections_example
trait BaseExtension {
  def init
  //def name : String
  val name: String
  override def toString: String = {
    name
  }
}
