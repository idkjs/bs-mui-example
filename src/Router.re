let str = ReasonReact.stringToElement;

module RouterConfig = {
  type route =
    | Home
    | ExampleList
    | ExampleClassOverride
    | ExampleWithStylesSafe
    | ExampleWithStylesUnsafe;
  let routeFromUrl = (url: ReasonReact.Router.url) =>
    switch (url.path) {
    | [] => Home
    | ["exampleList"] => ExampleList
    | ["exampleClassOverride"] => ExampleClassOverride
    | ["exampleWithStylesUnsafe"] => ExampleWithStylesUnsafe
    | ["exampleWithStylesSafe"] => ExampleWithStylesSafe
    | _ => Home
    };
  let routeToUrl = (route: route) =>
    switch (route) {
    | Home => "/"
    | ExampleList => "/exampleList"
    | ExampleClassOverride => "/exampleClassOverride"
    | ExampleWithStylesUnsafe => "/exampleWithStylesUnsafe"
    | ExampleWithStylesSafe => "/exampleWithStylesSafe"
    };
};

module Router = ReRoute.CreateRouter(RouterConfig);

let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <Router.Container>
      ...(
           (~currentRoute) =>
             <div className="container">
               <div className="nav">
                 <div className="active">
                   <Router.Link route=Home> (str("Home")) </Router.Link>
                 </div>
                 <div>
                   <Router.Link route=ExampleList>
                     (str("ExampleList"))
                   </Router.Link>
                 </div>
                 <div>
                   <Router.Link route=ExampleClassOverride>
                     (str("ExampleClassOverride"))
                   </Router.Link>
                 </div>
                 <div>
                   <Router.Link route=ExampleWithStylesUnsafe>
                     (str("ExampleWithStylesUnsafe"))
                   </Router.Link>
                 </div>
                 <div>
                   <Router.Link route=ExampleWithStylesSafe>
                     (str("ExampleWithStylesSafe"))
                   </Router.Link>
                 </div>
               </div>
               (
                 switch (currentRoute) {
                 | RouterConfig.Home => <Home />
                 | RouterConfig.ExampleList => <ExampleList />
                 | RouterConfig.ExampleClassOverride =>
                   <ExampleClassOverride />
                 | RouterConfig.ExampleWithStylesUnsafe =>
                   <ExampleWithStylesUnsafe />
                 | RouterConfig.ExampleWithStylesSafe =>
                   <ExampleWithStylesSafe />
                 }
               )
             </div>
         )
    </Router.Container>,
};