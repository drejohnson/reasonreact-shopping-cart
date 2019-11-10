module type Config = {
  type route;

  let toUrl: route => string;
  let toRoute: ReasonReact.Router.url => route;
};

module Config = {
  type route =
    | Home
    | Cart
    | NotFound;

  let toRoute = (url: ReasonReact.Router.url) => {
    switch (url.path) {
    | [] => Home
    | ["cart"] => Cart
    | _ => NotFound
    };
  };

  let toUrl =
    fun
    | Home => "/"
    | Cart => "/cart"
    | NotFound => "/404";
};

module Link = {
  [@react.component]
  let make = (~route, ~style=?, ~className, ~children) => {
    let href = Config.toUrl(route);
    let onClick = e => {
      ReactEvent.Mouse.preventDefault(e);
      ReasonReact.Router.push(href);
    };
    <a href onClick ?style ?className> children </a>;
  };
};