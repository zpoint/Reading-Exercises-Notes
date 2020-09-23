function Warning(props) {
	if (!props.warning) {
  	return null;
  }
  return (<div className="Warning">Warning!!!</div>)
}

class Page extends React.Component {
	constructor(props) {
  	super(props);
    this.state = {warning: false};
    this.handleWarning = this.handleWarning.bind(this);
  }
  
  handleWarning() {
  	this.setState(state => ({warning: !state.warning}));
  }
  
  render() {
  return (<div>
    <Warning warning={this.state.warning} />
    <button onClick={this.handleWarning} >{this.state.warning ? "HIDE" : "SHOW"}</button>
  </div>)
  }

}