[@react.component]
let make = _ => {
  let (cart, removeItem) = React.useContext(CartContext.context);
  let (total, setTotal) = React.useState(() => 0);

  React.useEffect2(
    () => {
      let add = (acc, value: BookData.book) =>
        acc + int_of_float(value.price);
      let cartTotal = Belt.List.reduce(cart, 0, add);
      setTotal(_ => cartTotal);
      None;
    },
    (total, removeItem),
  );

  let cartItems =
    cart->Belt.List.map((book: BookData.book) =>
      <CartItem key={Js.Int.toString(book.rank)} book removeItem />
    );
  <div className=Cart_Styles.cartItems>
    {Array.of_list(cartItems)->ReasonReact.array}
    <div>
      <p>
        "Total : "->React.string
        <span> {"$" ++ Js.Int.toString(total) |> React.string} </span>
      </p>
      <button> "Checkout"->React.string </button>
    </div>
  </div>;
};

let default = make;