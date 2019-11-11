open Loadable;

module Books = {
  module type T = (module type of Books);
  [@bs.val] external component: (module T) = "undefined";
  module Lazy: T = {
    include (val component);
    let make = lazy_(() => import("./Books/Books.bs"));
    let default = make;
  };
};

module Cart = {
  module type T = (module type of Cart);
  [@bs.val] external component: (module T) = "undefined";
  module Lazy = {
    include (val component);
    let make = lazy_(() => import("./Cart/Cart.bs"));
    let default = make;
  };
};

module NotFound = {
  module type T = (module type of NotFound);
  [@bs.val] external component: (module T) = "undefined";
  module Lazy = {
    include (val component);
    let make = lazy_(() => import("./NotFound/NotFound.bs"));
    let default = make;
  };
};