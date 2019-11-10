module Styles = {
  open Css;

  let bookList =
    style([
      display(grid),
      gridTemplateColumns([
        `repeat((`autoFit, `minmax((px(225), fr(1.0))))),
      ]),
      gridGap(rem(1.0)),
      padding3(~top=rem(6.), ~h=rem(1.), ~bottom=rem(2.)),
    ]);
};

[@react.component]
let make = (~books, ~addItem) => {
  let bookList =
    books
    |> List.map((book: BookData.book) =>
         <Book key={Js.Int.toString(book.rank)} book addItem />
       );
  <div className=Styles.bookList>
    {Array.of_list(bookList)->ReasonReact.array}
  </div>;
};