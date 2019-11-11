module AppRouter = Router.Create(Route.Config);

module Styles = {
  open Css;

  let wrapper =
    style([
      backgrounds([
        linearGradient(
          deg(0.),
          [(zero, rgba(0, 0, 0, 0.5)), (pct(100.), rgba(0, 0, 0, 0.5))],
        ),
        url(
          "https://images.unsplash.com/photo-1507842217343-583bb7270b66?ixlib=rb-1.2.1&ixid=eyJhcHBfaWQiOjEyMDd9&auto=format&fit=crop&w=1453&q=80",
        ),
      ]),
      backgroundPosition(pct(50.), pct(50.0)),
      backgroundRepeat(noRepeat),
      width(pct(100.0)),
      height(vh(100.0)),
      overflow(scroll),
    ]);
};

open UseFetch;

[@react.component]
let make = () => {
  let state =
    useFetch(
      "https://api.nytimes.com/svc/books/v3/lists/current/hardcover-fiction.json?api-key=6lCoWhaoHYUhjkpKwujA5sd3scna08JC",
    );
  let (cart, setCart) = React.useState(() => []);

  let addItem = (book: BookData.book) => {
    setCart(_ => [book, ...cart]);
    let encodedCart = BookData.books_encode(cart);
    Dom.Storage.(
      localStorage |> setItem("cart-items", Json.stringify(encodedCart))
    );
  };

  let removeItem = id => {
    let book =
      cart->Belt.List.keep((book: BookData.book) => book.rank !== id);
    setCart(_ => book);
    let encodedCart = BookData.books_encode(cart);
    Dom.Storage.(
      localStorage |> setItem("cart-items", Json.stringify(encodedCart))
    );
  };

  React.useEffect1(
    () => {
      let encodedCart = BookData.books_encode(cart);
      Dom.Storage.(
        localStorage |> setItem("cart-items", Json.stringify(encodedCart))
      );
      None;
    },
    [|cart|],
  );

  <BooksContext.Provider value=(state, addItem)>
    <CartContext.Provider value=(cart, removeItem)>
      <React.Suspense
        fallback={<div> {ReasonReact.string("Loading ...")} </div>}>
        <div className=Styles.wrapper>
          <Navigation />
          <AppRouter>
            {currentRoute =>
               Route.Config.(
                 switch (currentRoute) {
                 | Home => <Pages.Books.Lazy />
                 | Cart => <Pages.Cart.Lazy />
                 | NotFound =>
                   <div> "Page not found :/"->ReasonReact.string </div>
                 }
               )}
          </AppRouter>
        </div>
      </React.Suspense>
    </CartContext.Provider>
  </BooksContext.Provider>;
};