package LOOHCS;

import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;
public class StudentM {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		JFrame myframe=new SFrame();
	      myframe.show();
	}

}

class SFrame extends JFrame implements ActionListener,ItemListener{
    private Connection con=null;
    private Statement stmt=null;
    private ResultSet  rs=null;
    private JLabel conditionlabel
        =new JLabel (" ",SwingConstants.CENTER);
    private JLabel snolabel=new JLabel("ѧ��:",SwingConstants.RIGHT);
    private JTextField sno=new JTextField(11);
    private JLabel snamelabel=new JLabel("����:",SwingConstants.RIGHT);
    private JTextField sname=new JTextField(8);
    private JLabel addresslabel=new JLabel("��ַ:",SwingConstants.RIGHT);
    private JLabel genderlabel=new JLabel("�Ա�:",SwingConstants.RIGHT);
    private ButtonGroup gen=new ButtonGroup();
    private JRadioButton male=new JRadioButton("��");
    private JRadioButton female=new JRadioButton("Ů");
    private JTextField address=new JTextField(20);
    private JLabel titlelabel=new JLabel("ѧ��                    ����                      �Ա�                     ��ַ             ",SwingConstants.RIGHT);
    private JButton commit=new JButton("��ѯ");
    private JButton insert=new JButton("����");
    private JButton change=new JButton("�޸�");
    private JButton delete=new JButton("ɾ��");
    private JLabel resultarea=new JLabel("  ");  
    private JTextArea resarea=new JTextArea(10,30); 
    private  String command=null;
    private  String sex="";
    @SuppressWarnings("deprecation")
	public SFrame(){
        setTitle("ѧ����Ϣ����");
        setSize(550,350); 
        addWindowListener(new WindowAdapter(){
           public void windowClosing(WindowEvent e)
               { dispose(); }
        });
        getContentPane().setLayout(new GridBagLayout());
           //ʹ��GridBagLayout���ֱ���Swing���
        GridBagConstraints gbc=new GridBagConstraints();
        gbc.fill=GridBagConstraints.NONE;
        gbc.anchor=GridBagConstraints.CENTER; 
        gbc.weightx=100;
        gbc.weighty=100;
        add(conditionlabel,gbc,1,0,7,1);
        JScrollPane scrollpane=new JScrollPane(resarea);
        resarea.setEditable(false);
        resarea.setLineWrap(true);//�Զ�����
        gbc.anchor=GridBagConstraints.EAST; 
        add(snolabel,gbc,2,1,1,1); 
        add(snamelabel,gbc,4,1,1,1); 
        add(addresslabel,gbc,2,2,1,1); 
        add(genderlabel,gbc,4,2,1,1);
        gbc.anchor=GridBagConstraints.WEST;
        add(sno,gbc,3,1,1,1);
        add(sname,gbc,5,1,5,1);
        add(address,gbc,3,2,1,1);
        gen.add(male); 
        gen.add(female);
        add(male,gbc,5,2,1,1);
        add(female,gbc,6,2,1,1);
        male.addItemListener(this);
        female.addItemListener(this);
        add(resultarea,gbc,3,3,4,1);
        gbc.anchor=GridBagConstraints.NORTH;
        add(titlelabel,gbc,3,4,3,1);
        add(scrollpane,gbc,3,5,3,4);
        gbc.anchor=GridBagConstraints.NORTHWEST;
        add(commit,gbc,6,5,1,1);
        add(insert,gbc,6,6,1,1);
        add(change,gbc,6,7,1,1); 
        add(delete,gbc,6,8,1,1);
        commit.addActionListener(this);
        insert.addActionListener(this);
        change.addActionListener(this);
        delete.addActionListener(this);
        commit.setNextFocusableComponent(sno); 

        try{
           Class.forName("com.mysql.jdbc.Driver");
           con=DriverManager.getConnection("jdbc:mysql://localhost:3306/school?autoReconnect=true&useUnicode=true&characterEncoding=UTF-8","root","1216");
           stmt=con.createStatement();
        } catch(Exception ex) {
           resultarea.setText(ex.getMessage()+"\n"); 
           return;
        }
      }
      public void add(Component c,GridBagConstraints gbc,int x,int y,
         int w, int h) {
         gbc.gridx=x;
         gbc.gridy=y;
         gbc.gridwidth=w;
         gbc.gridheight=h;
         getContentPane().add(c,gbc);
      }
      public void itemStateChanged(ItemEvent I) {
    	  if(I.getSource()==male){
    	      sex="��";	 
    	  }
    	  else if(I.getSource()==female){
    	      sex="Ů";
    	  }
    	  else  sex="";
      }
      public void actionPerformed(ActionEvent evt) {
    	 String snovalue=sno.getText().trim();
    	 String snamevalue=sname.getText().trim();
    	 String addressvalue=address.getText().trim();
    	 if(evt.getSource()==commit){
    		 String ssno=" LIKE '%"+snovalue+"%'";//֧��ģ������
    		 String ssname=" LIKE '%"+snamevalue+"%'";//֧��ģ������
    		 String saddress=" LIKE '%"+addressvalue+"%'";//֧��ģ������
    		 if(!sex.equals("")){
    		 command="SELECT * FROM student WHERE sno"+ssno+" AND sname"+ssname+" AND gender='"+sex+"' AND address"+saddress+" ORDER BY sno DESC";
    		 }
    		 else {
        		 command="SELECT * FROM student WHERE sno"+ssno+" AND sname"+ssname+" AND address"+saddress+" ORDER BY sno DESC";
        	}
    			 try{
                 rs=stmt.executeQuery(command);
                 if(rs.next()) 
                 { 
                       resultarea.setText("��ѯ�ɹ�");
                       resarea.setText("");
                       do{
                           String resno=rs.getString("sno").trim();
                           String resname=rs.getString("sname").trim();
                           String regen=rs.getString("gender").trim();
                           String read=rs.getString("address").trim();
                           resarea.append(resno);//����
                           resarea.append("\t");
                           resarea.append(resname);//����
                           resarea.append("\t");
                           resarea.append(regen);//����
                           resarea.append("\t");
                           resarea.append(read+"\n"); 
                       }while(rs.next());
                 } 
                   else{
                	   resultarea.setText("�޷��������ļ�¼");
                	   resarea.setText("");
                   } 
                 sex="";
               }
            catch(Exception ex) {
               resultarea.setText(ex.getMessage()+"\n"+command+"\n");
           }
    	 }
    	 else if(evt.getSource()==insert){
    		 if(!snovalue.equals("")){
    		 command="SELECT * FROM student WHERE sno="+snovalue;
                try{
                   rs=stmt.executeQuery(command);
                    if(rs.next()) 
                       resultarea.setText("�ظ����Ƿ���£�");
                     else{
                        command="insert into student values("+snovalue+",'"+snamevalue+"','"+sex+"','"+addressvalue+"')"; 
                           try{
                              stmt.executeUpdate(command);
                              resultarea.setText("�ɹ�����һ��ѧ����Ϣ");
                               }catch(Exception ex) {
                                     resultarea.setText(ex.getMessage());}
                          } 
                    }catch(Exception ex) {
                           resultarea.setText(ex.getMessage()+"\n"+command+"\n");
                       }
    		 }
    		 else
    			 resultarea.setText("������ѧ����Ϣ");
         } 
    	 else if(evt.getSource()==delete){
    		 if(!snovalue.equals("")){
    			 command="delete from student where sno="+snovalue;
    			 try{
               	     stmt.executeUpdate(command);
                     resultarea.setText("ɾ���ɹ�");
                   }
                 catch(Exception ex) {
                   resultarea.setText(ex.getMessage());
                  }
    			 }
    		 else if(!snamevalue.equals("")){
    			 command="delete from student where sname='"+snamevalue+"'";
    		 try{
           	     stmt.executeUpdate(command);
                 resultarea.setText("ɾ���ɹ�");
               }
             catch(Exception ex) {
               resultarea.setText(ex.getMessage());
              }
    	 }
    	 else
			 resultarea.setText("ɾ��ʧ��");
    	 }
    	 else if(evt.getSource()==change){
    		 if(!snamevalue.equals("")){
    			 command="update student set sname='"+snamevalue+ "' where sno="+snovalue;
        		 try{
               	     stmt.executeUpdate(command);
                     resultarea.setText("�ɹ�����һ��ѧ����Ϣ");
                   }
                 catch(Exception ex) {
                   resultarea.setText(ex.getMessage());
                  }
    		 }
    		 if(!sex.equals("")){
    			 command="update student set gender='"+sex+ "' where sno="+snovalue;
        		 try{
               	     stmt.executeUpdate(command);
                     resultarea.setText("�ɹ�����һ��ѧ����Ϣ");
                   }
                 catch(Exception ex) {
                   resultarea.setText(ex.getMessage());
                  }
        		 }
    		 if(!addressvalue.equals("")){
    			 command="update student set address='"+addressvalue+ "' where sno="+snovalue;
        		 try{
               	     stmt.executeUpdate(command);
                     resultarea.setText("�ɹ�����һ��ѧ����Ϣ");
                   }
                 catch(Exception ex) {
                   resultarea.setText(ex.getMessage());
                  }
        		 }
    		 if(addressvalue.equals("")&sex.equals("")&snamevalue.equals(""))
    			 resultarea.setText("������Ҫ���µ���Ϣ");
    	 }
    	 
    }
}