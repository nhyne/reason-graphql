module TodoLists = [%graphql
  {|
  query TodoLists {
        getTodoList(todoListId: 2) {
        id
        name
    }
  }
|}
];

module TodoListQuery = ReasonApollo.CreateQuery(TodoLists);

[@react.component]
let make = () => {
  let todoListsQuery = TodoLists.make();
  <div>
    <p> {ReasonReact.string("something")} </p>
    <TodoListQuery variables=todoListsQuery##variables>
      ...{({result}) =>
        switch (result) {
        | Loading => <div> {ReasonReact.string("loading...")} </div>
        | Error(error) => <div> {ReasonReact.string(error.message)} </div>
        | Data(response) =>
          <div> {ReasonReact.string("we got data somehow")} </div>
        //          <div>
        //            {ReasonReact.string(
        //               response##getTodoList
        //               ->Belt.Option.mapWithDefault("default", list => list##name),
        //             )}
        //          </div>
        }
      }
    </TodoListQuery>
  </div>;
};
