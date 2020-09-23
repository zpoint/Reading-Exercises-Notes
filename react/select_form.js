class FlavorForm extends React.Component {
  constructor(props) {
    super(props);
    this.state = {value: "Lime"};
    this.onChange = this.onChange.bind(this);
    this.onSubmit = this.onSubmit.bind(this);
  }
  
  onChange(event) {
    this.setState({value: event.target.value});
  }
  
  onSubmit(event) {
    alert("Submit: " + this.state.value);
    event.preventDefault();
  }
  
  render() {
  return (<form onSubmit={this.onSubmit} >
  <label>
    Pick your favourite flavor:
    <select value={this.state.value} onChange={this.onChange} >
    <option value="Grapefruit">Grapefruit</option>
    <option value="Lime">Lime</option>
    <option value="Coconut">Coconut</option>
    <option value="Mango">Mango</option>
    </select>
  </label>
  <input type="submit" value="Submit" />
  </form>)
  }

}

ReactDOM.render(<FlavorForm />, document.querySelector("#app"))
