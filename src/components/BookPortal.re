[@bs.val] external document: Js.t({..}) = "document";

module Styles = {
  open Css;

  let wrapper =
    style([
      position(absolute),
      top(zero),
      color(hex("111")),
      backgroundColor(white),
      width(pct(100.)),
      height(vh(100.)),
      padding(rem(2.)),
    ]);

  let close =
    style([
      display(flexBox),
      justifyContent(flexEnd),
      fontFamily("'Montserrat', sans-serif"),
      fontSize(rem(2.)),
      width(pct(100.)),
      hover([cursor(`pointer)]),
    ]);

  let details =
    style([
      display(grid),
      gridTemplateColumns([pct(25.), fr(1.)]),
      gridGap(rem(1.)),
      alignItems(center),
      justifyContent(center),
      height(pct(100.)),
    ]);

  let imgWrapper =
    style([display(flexBox), width(pct(100.)), height(pct(100.))]);

  let img = style([objectFit(contain)]);

  let bookInfo = style([maxWidth(px(600)), padding(rem(1.))]);
};

[@react.component]
let make = (~book: BookData.book, ~show: bool, ~close, ~addItem) => {
  let portal =
    ReactDOMRe.createPortal(
      <div className=Styles.wrapper>
        <span className=Styles.close onClick=close> "X"->React.string </span>
        <div className=Styles.details>
          <div className=Styles.imgWrapper>
            <img className=Styles.img src={book.book_image} />
          </div>
          <div className=Styles.bookInfo>
            <h4>
              "Ranked number"->React.string
              {Js.Int.toString(book.rank)->React.string}
            </h4>
            <h2> book.title->React.string </h2>
            <p> book.description->React.string </p>
            <p> "Written by"->React.string book.author->React.string </p>
            <p> "Published by"->React.string book.publisher->React.string </p>
            <p>
              "Price: "->React.string
              <span>
                {React.string("$" ++ Js.Float.toString(book.price))}
              </span>
            </p>
          </div>
          <button onClick={_ => addItem(book)}>
            <span onClick=close> "Add to cart"->React.string </span>
          </button>
        </div>
      </div>,
      document##body,
    );

  show ? portal : React.null;
};