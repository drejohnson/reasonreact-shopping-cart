[@bs.val] external document: Js.t({..}) = "document";

Css.(global("html", [boxSizing(borderBox)]));
Css.(global("*, *::before, *::after", [boxSizing(inherit_)]));
Css.(global("*", [minWidth(zero), minHeight(zero)]));
Css.(global("html, body", [margin(zero), padding(zero)]));
Css.(
  global(
    "body",
    [
      color(hex("fff")),
      fontSize(rem(1.)),
      fontFamily(
        "-apple-system, BlinkMacSystemFont, 'Segoe UI', 'Roboto', 'Oxygen',
      'Ubuntu', 'Cantarell', 'Fira Sans', 'Droid Sans', 'Helvetica Neue',
      sans-serif",
      ),
    ],
  )
);
Css.(
  global(
    "h1,h2,h3,h4,h5,h6,",
    [
      fontFamily("'Montserrat', sans-serif;"),
      fontWeight(`num(500)),
      margin(zero),
    ],
  )
);
Css.(global("img", [width(pct(100.0)), height(auto)]));

let root = document##querySelector("#root");
ReactDOMRe.render(<App />, root);