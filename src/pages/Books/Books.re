[@react.component]
let make = _ => {
  let (state, addItem) = React.useContext(BooksContext.context);
  switch (state) {
  | Error => <div> {React.string("An error occurred!")} </div>
  | Loading => <div> {React.string("Loading...")} </div>
  | Loaded(books) => <BookList books addItem />
  };
};

let default = make;