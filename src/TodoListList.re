/* VideoGameList.re */
open TodoList;

let str = ReasonReact.string;
[@react.component]
let make = (~items) => {
  <ul style={ReactDOMRe.Style.make(~listStyleType="none", ())}>
    {items
     |> Array.map(todoListFromJs)
     |> Array.map(item =>
          <li key={string_of_int(item.id)}>
            <input
              id={string_of_int(item.id)}
              type_="checkbox"
              checked=false
            />
            <label htmlFor={string_of_int(item.id)}>
              {ReasonReact.string(item.name)}
            </label>
          </li>
        )
     |> ReasonReact.array}
  </ul>;
};
