let initialState: (UseFetch.state, BookData.book => unit) = (
  UseFetch.Loading,
  _ => (),
);
let context = React.createContext(initialState);

module Provider = {
  let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };

  let make = React.Context.provider(context);
};