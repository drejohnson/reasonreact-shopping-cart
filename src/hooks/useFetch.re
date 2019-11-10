type state =
  | Loading
  | Error
  | Loaded(list(BookData.book));

type action =
  | BooksFetch
  | BooksFetched(list(BookData.book))
  | BooksFailedToFetch;

exception PostError(string);

let useFetch = (url: string) => {
  let (state, dispatch) =
    React.useReducer(
      (_state, action) =>
        switch (action) {
        | BooksFetch => Loading
        | BooksFetched(books) => Loaded(books)
        | BooksFailedToFetch => Error
        },
      Loading,
    );

  React.useEffect0(() => {
    open BookData;
    Js.Promise.(
      Fetch.fetch(url)
      |> then_(Fetch.Response.json)
      |> then_(response =>
           response |> response_decode |> Belt.Result.getExn |> resolve
         )
      |> then_(({results}) =>
           {
             let transformedBooks =
               results.books
               ->Belt.List.map(book =>
                   {
                     ...book,
                     price:
                       GeneratePrice.generatePrice(10., 60.)
                       |> Js.Float.fromString,
                   }
                 );
             dispatch(BooksFetched(transformedBooks));
           }
           |> resolve
         )
      |> catch(err => {
           dispatch(BooksFailedToFetch);
           reject(ResError(err));
         })
    )
    |> ignore;
    None;
  });
  state;
};