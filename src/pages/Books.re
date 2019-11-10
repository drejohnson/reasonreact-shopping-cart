module Styles = {
  open Css;

  let products = style([
    display(grid),
    gridTemplateColumns([`repeat(`autoFit, `minmax(px(320), fr(1.0)))]),
    gridGap(rem(1.0))
  ])
}

[@react.component]
let make = (_) => {
  let (state, addItem) = React.useContext(BooksContext.context);
  switch (state) {
    | Error => <div> {React.string("An error occurred!")} </div>
    | Loading => <div> {React.string("Loading...")} </div>
    | Loaded(books) =>
      <BookList books={books} addItem={addItem}/>
    };
};