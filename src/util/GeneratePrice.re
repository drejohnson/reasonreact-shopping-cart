let generatePrice = (min: float, max: float) => {
  let num = Js.Math.random() *. (max -. min) +. min;
  num -> Js.Float.toFixed
}