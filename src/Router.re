let str = ReasonReact.stringToElement;

module RouterConfig = {
  type route =
    | ExampleList
    | ExampleClassOverride
    | ExampleWithStylesSafe
    | ExampleWithStylesUnsafe;
  let routeFromUrl = (url: ReasonReact.Router.url) =>
    switch (url.path) {
    | [] => ExampleList
    | ["exampleList"] => ExampleList
    | ["exampleClassOverride"] => ExampleClassOverride
    | ["exampleWithStylesUnsafe"] => ExampleWithStylesUnsafe
    | ["exampleWithStylesSafe"] => ExampleWithStylesSafe
    | _ => ExampleList
    };
  let routeToUrl = (route: route) =>
    switch (route) {
    | ExampleList => "/exampleList"
    | ExampleList => "/"
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
             <div>
               <nav>
                 <div className="active">
                   <Router.Link route=ExampleList>
                     (str("ExampleList"))
                     <span className="fa fa-music" />
                   </Router.Link>
                 </div>
                 <div>
                   <Router.Link route=ExampleClassOverride>
                     (str("ExampleClassOverride"))
                   </Router.Link>
                   <span className="fa fa-search" />
                 </div>
                 <div>
                   <Router.Link route=ExampleWithStylesUnsafe>
                     (str("ExampleWithStylesUnsafe"))
                     <span className="fa fa-list" />
                   </Router.Link>
                 </div>
                 <div>
                   <Router.Link route=ExampleWithStylesSafe>
                     (str("ExampleWithStylesSafe"))
                     <span className="fa fa-search" />
                   </Router.Link>
                 </div>
               </nav>
               (
                 switch (currentRoute) {
                 /* | RouterConfig.Home => <Home /> */
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