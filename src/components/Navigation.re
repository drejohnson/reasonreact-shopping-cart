module Styles = {
  open Css;

  let header = style([
    position(fixed),
    display(flexBox),
    alignItems(center),
    justifyContent(spaceBetween),
    color(hex("fff")),
    backgroundImage(linearGradient(deg(45.), [(zero, rgba(255, 255, 255, 0.9)), (pct(100.), rgba(255, 255, 255, 0.9))])),
    width(pct(100.)),
    height(rem(4.0)),
    padding2(~v=zero, ~h=rem(1.0))
  ])

  let logo = style([
    display(flexBox),
    alignItems(center)
  ]);

  let img = style([
    width(px(40))
  ]);

  let logoSpan = style([
    color(hex("111")),
    margin2(~v = zero, ~h = rem(1.))
  ])
  let nav = style([
    display(flexBox),
    justifyContent(flexEnd),
    alignItems(center),
    flex(`num(1.))
  ])
  let navLink = style([
    display(flexBox),
    alignItems(center),
    color(hex("111")),
    textDecoration(none),
    marginLeft(rem(0.875))
  ])
  let linkSpan = style([
    display(flexBox),
    justifyContent(center),
    alignItems(center),
    backgroundColor(hex("111")),
    color(white),
    width(rem(2.)),
    height(rem(2.)),
    borderRadius(px(30)),
    marginLeft(rem(0.5))
  ])
}

[@react.component]
let make = _ => {
  let (cart, _) = React.useContext(CartContext.context);
  Js.log(cart->Belt.List.length);
  <div className={Styles.header}>
    <div className={Styles.logo}>
      <img className={Styles.img} src={"https://s3-us-west-2.amazonaws.com/s.cdpn.io/387928/nyt-logo.png"} />
      <span className={Styles.logoSpan}>{"Best Sellers List"->React.string}</span>
    </div>
    <nav className={Styles.nav}>
      <Route.Link route={Route.Config.Home} className={Some(Styles.navLink)}>{"Home"->React.string}</Route.Link>
      <Route.Link 
        route={Route.Config.Cart} 
        className={Some(Styles.navLink)}>
          {"Cart" -> React.string}
          <span className={Styles.linkSpan}>
            {{Belt.List.length(cart)->Js.Int.toString} -> React.string}
          </span>
        </Route.Link>
    </nav>
  </div>
};