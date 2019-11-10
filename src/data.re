// type t = {
 //   id: int,
 //   title: string,
 //   price: float,
 //   image: string,
 // };
 // type book = {
 //   rank: int,
 //   title: string,
 //   description: string,
 //   price: float,
 //   book_image: string,
 //   author: string,
 //   publisher: string,
 // };
 // type bookResult = {books: list(book)};
 // type bookResponse = {results: bookResult};
 // module Decode = {
 //   let book = json =>
 //     Json.Decode.{
 //       rank: field("rank", int, json),
 //       title: field("title", string, json),
 //       description: field("description", string, json),
 //       price: field("price", float, json),
 //       book_image: field("book_image", string, json),
 //       author: field("author", string, json),
 //       publisher: field("publisher", string, json),
 //     };
 //   let results = json =>
 //     Json.Decode.{books: json |> field("books", list(book))};
 //   let response = json =>
 //     Json.Decode.{results: json |> field("results", results)};
 //   let books = json =>
 //     Json.Decode.{books: json |> field("books", list(book))};
 //   // let book = json =>
 //   // 	Json.Decode.{
 //   // 		rank: field("rank", int, json),
 //   // 		title: field("title", string, json),
 //   // 		description: field("description", string, json),
 //   // 		price: field("price", int, json),
 //   // 		book_image: field("book_image", string, json),
 //   // 		author: field("author", string, json)
 //   // 	};
 //   // let books = (json): list(book) =>
 //   //   Json.Decode.(
 //   //     json |> field("books", list(book)) |> List.map(book => book),
 //   //   );
 // };
 // let books = [
 //   {
 //     id: 1,
 //     title: "The Art Of War",
 //     price: 10.11,
 //     image: "https://images-na.ssl-images-amazon.com/images/I/41FBMkY3cgL._SX331_BO1,204,203,200_.jpg",
 //   },
 //   {
 //     id: 2,
 //     title: "Civilization and Its Discontents",
 //     price: 14.29,
 //     image: "https://images-na.ssl-images-amazon.com/images/I/51Jj12iMZnL._SX331_BO1,204,203,200_.jpg",
 //   },
 //   {
 //     id: 3,
 //     title: "Influence: The Psychology of Persuasion",
 //     price: 10.98,
 //     image: "https://images-na.ssl-images-amazon.com/images/I/512-B-1yXuL._SX331_BO1,204,203,200_.jpg",
 //   },
 //   {
 //     id: 4,
 //     title: "Grokking Algorithms",
 //     price: 40.00,
 //     image: "https://images-na.ssl-images-amazon.com/images/I/51llKt2oJEL._SX333_BO1,204,203,200_.jpg",
 //   },
 /* ]*/