type state =
  | Loading
  | Error
  | Loaded(Js.Json.t);

type action =
  | Fetching
  | FetchSuccess(Js.Json.t)
  | FailedToFetch;

exception Error(Js.Promise.error);

let useFetch = (url: string) => {
  let (state, dispatch) =
    React.useReducer(
      (_state, action) =>
        switch (action) {
        | Fetching => Loading
        | FetchSuccess(value) => Loaded(value)
        | FailedToFetch => Error
        },
      Loading,
    );

  React.useEffect0(() => {
    Js.Promise.(
      Fetch.fetch(url)
      |> then_(Fetch.Response.json)
      |> then_(response => dispatch(FetchSuccess(response)) |> resolve)
      |> catch(err => {
           dispatch(FailedToFetch);
           reject(Error(err));
         })
    )
    |> ignore;
    None;
  });
  state;
};