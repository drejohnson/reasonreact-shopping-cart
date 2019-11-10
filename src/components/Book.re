open ReasonTransitionGroup;

module Styles = {
  open Css;

  let book =
    style([
      display(grid),
      gridTemplateRows([fr(1.0), pct(25.0)]),
      gridGap(rem(1.0)),
      hover([cursor(`pointer)]),
    ]);

  let imgWrapper =
    style([display(flexBox), width(pct(100.)), height(pct(100.))]);

  let img = style([objectFit(contain)]);

  let bookInfo =
    style([
      // display(flexBox),
      // flexDirection(column),
      justifySelf(center),
    ]);

  let portalEnter =
    style([
      opacity(0.),
      transform(`scale((0.9, 0.9))),
      label("portal-enter"),
    ]);
  let portalEnterActive =
    style([
      opacity(1.),
      transform(`translateX(`zero)),
      transition(~duration=300, "all"),
      label("portal-enter-active"),
    ]);
  let portalExit = style([opacity(1.0), label("portal-exit")]);
  let portalExitActive =
    style([
      opacity(0.),
      transform(`scale((0.9, 0.9))),
      transition(~duration=300, "all"),
      label("portal-exit-active"),
    ]);
};

let classNames =
  `obj(
    CSSTransition.classFull(
      ~enter=Styles.portalEnter,
      ~enterActive=Styles.portalEnterActive,
      ~exit=Styles.portalExit,
      ~exitActive=Styles.portalExitActive,
      (),
    ),
  );

[@react.component]
let make = (~book: BookData.book, ~addItem) => {
  let (showDetails, setShowDetails) = React.useState(() => false);
  let (bookView, setBookView) = React.useState(() => book);
  let toggleDetails = _ => setShowDetails(_ => !showDetails);

  let viewDetails = rank => {
    [book]
    ->Belt.List.keep((book: BookData.book) => book.rank === rank)
    ->Belt.List.map(book => setBookView(_ => book))
    ->ignore;
    setShowDetails(_ => !showDetails);
  };

  <>
    <CSSTransition
      _in=showDetails timeout={`int(300)} classNames unmountOnExit=true>
      {_state =>
         <BookPortal
           book=bookView
           show=showDetails
           close=toggleDetails
           addItem
         />}
    </CSSTransition>
    <div className=Styles.book>
      <div className=Styles.imgWrapper onClick={_ => viewDetails(book.rank)}>
        <img className=Styles.img src={book.book_image} alt={book.title} />
      </div>
      <div className=Styles.bookInfo>
        <h2 className="title"> book.title->React.string </h2>
      </div>
    </div>
  </>;
};