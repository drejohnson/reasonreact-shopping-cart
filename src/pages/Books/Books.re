[@react.component]
let make = _ => {
  let (state, addItem) = React.useContext(BooksContext.context);
  let decoded = BookData.bookResponse_decode;
  switch (state) {
  | Error => <div> {React.string("An error occurred!")} </div>
  | Loading => <div> {React.string("Loading...")} </div>
  | Loaded(response) =>
    let decodedResponse = response |> decoded |> Belt.Result.getExn;
    let books = decodedResponse.results.books;
    <BookList books addItem />;
  };
};

let default = make;