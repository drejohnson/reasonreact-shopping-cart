module Create = (Config: Route.Config) => {
  type route = Config.route;
  type action =
    | UpdateRoute(route);

  type state = {route};

  [@react.component]
  let make = (~children) => {
    let (state, dispatch) =
      React.useReducer(
        (_state, action) =>
          switch (action) {
          | UpdateRoute(route) => {route: route}
          },
        {
          route:
            ReasonReact.Router.dangerouslyGetInitialUrl() |> Config.toRoute,
        },
      );
    ();

    React.useEffect0(() => {
      let watcherID =
        ReasonReact.Router.watchUrl(url =>
          UpdateRoute(Config.toRoute(url)) |> dispatch
        );
      Some(() => ReasonReact.Router.unwatchUrl(watcherID));
    });

    children(state.route);
  };
};