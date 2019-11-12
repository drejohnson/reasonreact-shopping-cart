[@decco]
type book = {
  rank: int,
  title: string,
  description: string,
  price: float,
  book_image: string,
  author: string,
  publisher: string,
};

[@decco]
type books = list(book);

[@decco]
type bookResult = {books};

[@decco]
type bookResponse = {results: bookResult};

exception ResError(Js.Promise.error);