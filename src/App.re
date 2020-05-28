module TodoLists = [%graphql
  {|
  query TodoLists {
        getTodoLists(limit: 5) {
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
    <TodoListQuery variables=todoListsQuery##variables>
      ...{({result}) =>
        switch (result) {
        | Loading => <div> {ReasonReact.string("loading...")} </div>
        | Error(error) => <div> {ReasonReact.string(error.message)} </div>
        | Data(data) => <TodoListList items={data##getTodoLists} />
        }
      }
    </TodoListQuery>
  </div>;
};
